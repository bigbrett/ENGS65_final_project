/*
 * Game.cpp
 *
 * Code to implement Game class
 *
 */

#include "Game.h"

//Game::Game(int startingNumAsteroids, int startingLives, int startingScore)
//:lives(startingLives), score(startingScore)
//{
//    // Create random number generator for placing asteroids on the field
//    default_random_engine generator;
//    uniform_int_distribution<int> y_gen (0, GAME_HEIGHT);
//    uniform_int_distribution<int> x_gen (0, GAME_WIDTH);
//    uniform_int_distribution<int> v_gen (0, ASTEROID_MAX_SPEED);
//    
//    // Put the ship into the list
//    objectsInPlay.push_front(ship);
//    
//    // Add the asteroids in
//    for(int i = 0; i < startingNumAsteroids; i++)
//    {
//        SDL_Point p;
//        p.x = x_gen(generator);
//        p.y = y_gen(generator);
//        Asteroid *temp = new Asteroid(ASTEROID_DEFAULT_SIZE, p,
//                                      v_gen(generator)/ASTEROID_DEFAULT_SIZE,
//                                      v_gen(generator)/ASTEROID_DEFAULT_SIZE);
//        objectsInPlay.push_back(temp);
//    }
//};


Game::Game(int startingNumAsteroids, int startingLives, int startingScore)
{
	lives = startingLives;
	score = startingScore;

	// Create random number generator for placing asteroids on the field
	default_random_engine generator;
	uniform_int_distribution <int> y_gen(0, GAME_HEIGHT);
	uniform_int_distribution <int> x_gen(0, GAME_WIDTH);
	uniform_int_distribution <int> v_gen(0, ASTEROID_MAX_SPEED);

	// Put the ship into the list
    ship = new Ship();
	objectsInPlay.push_front(ship);

	// Add the asteroids in
	for (int i = 0; i < startingNumAsteroids; i++) {
		SDL_Point p;
		p.x = x_gen(generator);
		p.y = y_gen(generator);
		Asteroid *temp = new Asteroid(ASTEROID_DEFAULT_SIZE, p,
		                              v_gen(generator) / ASTEROID_DEFAULT_SIZE,
		                              v_gen(generator) / ASTEROID_DEFAULT_SIZE);
		objectsInPlay.push_back(temp);
	}

    keyboardState = SDL_GetKeyboardState(NULL);
    
	this->renderer = new Renderer(this->window.gWindow);
	this->play();
}


Game::~Game()
{
    delete this->renderer;
}


/* Main Game loop */
void Game::play()
{
    cout << "starting game!!" << endl;
    while (this->graphicsDriver.isRunning())
    {
        // Handle events in the event queue
        this->handleEvents();
        
        // Check for pressed keys
        this->handleKeyboard();
        
        // Update game state
        this->updateState();
        
        // Draw the game
        this->drawGame();
    }
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
            graphicsDriver.exit();
        
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
        
        // Handle KeyDown event for U/D/R/L keys
        else if (eventQ.type == SDL_KEYDOWN)
        {
            switch (eventQ.key.keysym.scancode) {
                    
                    // Handle up key
                case SDL_SCANCODE_UP:
                    cout << "KeyDown UP!" << endl;
                    ship->setAccelerate(true);
                    break;
                    
                    // Handle down key
                case SDL_SCANCODE_DOWN:
                    cout << "KeyDown DOWN!" << endl;
                    break;
                    
                    // Handle left key
                case SDL_SCANCODE_LEFT:
                    cout << "KeyDown LEFT!" << endl;
                    ship->rotateCCW();
                    break;
                    
                    // Handle right key
                case SDL_SCANCODE_RIGHT:
                    cout << "KeyDown RIGHT!" << endl;
                    ship->rotateCW();
                    break;
                    
                    // Handle space
                case SDL_SCANCODE_SPACE:
                    cout << "KeyDown SPACEBAR" << endl;
                    break;
                    
                default:
                    break;
            } // switch
        }
        
        // Handle KeyUp event for U/D/R/L keys
        else if (eventQ.type == SDL_KEYUP)
        {
            switch (eventQ.key.keysym.scancode) {
                    // Handle up key
                case SDL_SCANCODE_UP:
                    cout << "KeyUp UP!" << endl;
                    ship->setAccelerate(false);
                    break;
                    
                    // Handle down key
                case SDL_SCANCODE_DOWN:
                    cout << "KeyUp DOWN!" << endl;
                    break;
                    
                    // Handle left key
                case SDL_SCANCODE_LEFT:
                    cout << "KeyUp LEFT!" << endl;
                    break;
                    
                    // Handle right key
                case SDL_SCANCODE_RIGHT:
                    cout << "KeyUp RIGHT!" << endl;
                    break;
                    
                    // Handle space
                case SDL_SCANCODE_SPACE:
                    cout << "KeyUp SPACEBAR" << endl;
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
    
    ship->move();
    
    return flag;
}



bool Game::drawGame()
{
	bool flag = true;

    
    renderer->clear();
	list <GameObject *>::iterator in_play_iter;
	if (!objectsInPlay.empty()) {
		for (in_play_iter = objectsInPlay.begin(); in_play_iter != objectsInPlay.end(); in_play_iter++) {
			(*in_play_iter)->draw(renderer->gRenderer);
		}
	}
	else
		flag = false;
    
    renderer->present();

	return flag;
}

void Game::handleKeyboard()
{
    if (keyboardState[SDL_SCANCODE_UP]) {
        cout << "KeyState Up" << endl;
    }
}
