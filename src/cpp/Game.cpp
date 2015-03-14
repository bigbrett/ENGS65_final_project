/*
 * Game.cpp
 *
 * Code to implement Game class
 *
 */

#include "Game.h"

Uint32 keyboardCallbackFunction(Uint32 interval, void *param);

Game::Game(int startingNumAsteroids, int startingLives, int startingScore)
{
	// Initialize player related game variables
	score = startingScore;
    
    // Initialize keyboard polling variables
    checkKeyboard = false;
    keyboardTimer = SDL_AddTimer(KEYBOARD_TIMER_INTERVAL,
                                 keyboardCallbackFunction, &checkKeyboard);

	// Create random number generator for placing asteroids on the field
	default_random_engine generator;
    uniform_int_distribution <int> x_gen(0, GAME_WIDTH);
	uniform_int_distribution <int> y_gen(0, GAME_HEIGHT);
	uniform_int_distribution <int> v_gen(ASTEROID_MIN_SPEED, ASTEROID_MAX_SPEED);
    
    // Seed code from:
    // http://www.cplusplus.com/reference/random/linear_congruential_engine/seed/
    typedef chrono::high_resolution_clock myclock;
    myclock::time_point beginning = myclock::now();
    myclock::duration d = myclock::now() - beginning;
    unsigned seed = d.count();
    generator.seed(seed);

	// Put the ship into the list
    ship = new Ship(startingLives);
	objectsInPlay.push_front(ship);
    
	// Add the asteroids in
	for (int i = 0; i < startingNumAsteroids; i++) {
		SDL_Point p;
		p.x = x_gen(generator);
		p.y = y_gen(generator);
		Asteroid *temp = new Asteroid(ASTEROID_DEFAULT_SIZE, p,
		                              v_gen(generator), v_gen(generator));
		objectsInPlay.push_back(temp);
	}

    keyboardState = SDL_GetKeyboardState(NULL);
    
    TextRenderer::initText();
    
	this->renderer = new Renderer(this->window.gWindow);
	this->play();
}


Game::~Game()
{
    delete this->renderer;
    TextRenderer::quitText();
}


/* Main Game loop */
void Game::play()
{
    cout << "Starting Game!!" << endl;
    
    while (this->graphicsDriver.isRunning())
    {
        
        // Handle events in the event queue
        this->handleEvents();
        
        if (ship->getLives() > 0 &&
               Asteroid::getNumAsteroidsRemaining() > 0)
        {
            // If we have reached the key-repeat delay, check the keyboard
            // Check for pressed keys
            if(checkKeyboard) this->handleKeyboard();
            
            // Update game state
            this->updateState();
        }
        
        // Draw the game
        this->drawGame();
    }
    cout << "Thanks for playing!" << endl;
}


/*
 * Event Handler for the game driver. Responds to user I/O
 */
void Game::handleEvents()
{
    // poll event queue to process events
    while (SDL_PollEvent(&eventQ))
    {
        
        // Handle quit event
        if (eventQ.type == SDL_QUIT)
        {
            SDL_RemoveTimer(keyboardTimer);
            graphicsDriver.exit();
        
        }
        // handle window events
        else if (eventQ.type == SDL_WINDOWEVENT)
        {
            // If mouse leaves window, pause and wait here until it comes back
            if (eventQ.window.event == SDL_WINDOWEVENT_FOCUS_LOST)
            {
                cout << "MOUSE FOCUS LOST" << endl;
                SDL_Event f; // new helper event
                f.type = SDL_WINDOWEVENT;
                f.window.event = SDL_WINDOWEVENT_FOCUS_GAINED;
                SDL_WaitEvent(&f); // wait for focus to return
                cout << "MOUSE RETURNED!" << endl;
            }
        }
        
        // Handle KeyUp event for U/D/R/L keys
        else if (eventQ.type == SDL_KEYUP)
        {
            switch (eventQ.key.keysym.scancode) {
                    // Handle up key
                case SDL_SCANCODE_UP:
                    ship->setAccelerate(false);
                    break;
                    
                    // Handle down key
                case SDL_SCANCODE_DOWN:
                    break;
                    
                    // Handle left key
                case SDL_SCANCODE_LEFT:
                    break;
                    
                    // Handle right key
                case SDL_SCANCODE_RIGHT:
                    break;
                    
                    // Handle space
                case SDL_SCANCODE_SPACE:
                    break;
                    
                default:
                    break;
            }// switch
        }// Keyup
        
    } // while
} // handleUserInput()

bool Game::updateState()
{
    bool flag = true;
    list <GameObject *>::iterator in_play_iter;
    list <GameObject *>::iterator in_play_iter_2;
    
    // Make everything move
    if (!objectsInPlay.empty())
    {
        for (in_play_iter = objectsInPlay.begin();
             in_play_iter != objectsInPlay.end(); in_play_iter++)
        {
            (*in_play_iter)->move();
        }
    }
    else
    {
        flag = false;
    }
    
    // Check for collisions
    if (!objectsInPlay.empty())
    {
        for (in_play_iter = objectsInPlay.begin();
             in_play_iter != objectsInPlay.end(); in_play_iter++)
        {
            for (in_play_iter_2 = in_play_iter;
                 in_play_iter_2 != objectsInPlay.end(); in_play_iter_2++)
            {
                if(in_play_iter != in_play_iter_2)
                {
                GameObject::collision(*in_play_iter, *in_play_iter_2);
                }
            }
        }
    }
    else
    {
        flag = false;
    }
    
    // Check for dead objects, remove them from play
    if(!objectsInPlay.empty())
    {
        for (in_play_iter = objectsInPlay.begin();
             in_play_iter != objectsInPlay.end(); in_play_iter++)
        {
            if((*in_play_iter)->isDestroyed())
            {
                list<GameObject*> *temp = (*in_play_iter)->destroy();
                if(!(temp->empty()))
                {
                    for (in_play_iter_2 = temp->begin();
                         in_play_iter_2 != temp->end(); in_play_iter_2++)
                    {
                        objectsInPlay.push_back((*in_play_iter_2));
                    }
                }
                delete temp;
                if((*in_play_iter)->getObjectType() == AGT_ASTEROID)
                {
                    score++;
                    if (score == SHIP_GUN_UPGRADE_SCORE) {
                        ship->upgradeGun();
                    }
                }
                delete (*in_play_iter); // delete the data at the location
                objectsInPlay.remove((*in_play_iter));  // remove the pointer
            }
        }
    }
    
    return flag;
}



bool Game::drawGame()
{
	bool flag = true;

    
    renderer->clear();
	list <GameObject *>::iterator in_play_iter;
	if (!objectsInPlay.empty())
    {
		for (in_play_iter = objectsInPlay.begin();
             in_play_iter != objectsInPlay.end(); in_play_iter++)
        {
			(*in_play_iter)->draw(renderer->gRenderer);
		}
	}
	else
		flag = false;
    
    TextRenderer::printGameData(renderer->gRenderer, ship->getLives(), score);
    
    if(ship->getLives()<=0)
    {
        TextRenderer::printGameOverLose(renderer->gRenderer);
    }
    else if(Asteroid::getNumAsteroidsRemaining() <= 0)
    {
        TextRenderer::printGameOverWin(renderer->gRenderer);
    }
    renderer->present();

	return flag;
}

void Game::handleKeyboard()
{
    // Handle up key
    if(keyboardState[SDL_SCANCODE_UP])
    {
        ship->setAccelerate(true);
    }
    
    // Handle down key
    if(keyboardState[SDL_SCANCODE_DOWN])
    {
    }
    
    // Handle left key
    if(keyboardState[SDL_SCANCODE_LEFT])
    {
        ship->rotateCCW();
    }
    
    // Handle right key
    if(keyboardState[SDL_SCANCODE_RIGHT])
    {
        ship->rotateCW();
    }
    
    // Handle space
    if(keyboardState[SDL_SCANCODE_SPACE])
    {
        list<Bullet*> *newBullets = ship->shoot();
        list <Bullet*>::iterator in_play_iter;
        if (!(newBullets->empty()))
        {
            for (in_play_iter = newBullets->begin();
                 in_play_iter != newBullets->end(); in_play_iter++)
            {
                objectsInPlay.push_back(*in_play_iter);
            }
            delete newBullets;
        }
    }
    
    checkKeyboard = false;
}

Uint32 keyboardCallbackFunction(Uint32 interval, void *param) {
    *((bool*)param) = true;
    return interval;
}
