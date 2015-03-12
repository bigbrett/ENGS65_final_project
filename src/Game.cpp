/*
 * Game.cpp
 *
 * Code to implement Game class
 *
 */

#include "Game.h"

Game::Game(int startingNumAsteroids, int startingLives, int startingScore)
:lives(startingLives), score(startingScore)
{
    // Create random number generator for placing asteroids on the field
    default_random_engine generator;
    uniform_int_distribution<int> y_gen (0, GAME_HEIGHT);
    uniform_int_distribution<int> x_gen (0, GAME_WIDTH);
    
    // Put the ship into the list
    objectsInPlay.push_front(ship);
    
    // Add the asteroids in
    for(int i = 0; i < startingNumAsteroids; i++)
    {
        SDL_Point p;
        p.x = x_gen(generator);
        p.y = y_gen(generator);
        Asteroid *temp = new Asteroid(ASTEROID_DEFAULT_SIZE, p);
        objectsInPlay.push_back(temp);
    }
};

Game::~Game()
{
	// TODO Auto-generated destructor stub
}

void Game::handleEvent(SDL_Event *e)
{
    // Check for Key Press
    if(e->type == SDL_KEYDOWN){
        if (e->key.keysym.sym == SDLK_SPACE) ship->shoot();
        else ship->handleKeyArrowPressEvent(e->key.keysym.sym);
    }
    
   // Don't do anything for any other events
}

bool Game::updateState()
{    
    /* Move() */
    
    /* Collisions */
    // Iterate through objectsInPlay, checking for collisions
        // If collision:
            // call dmg() on both
    
    /* Update list */
    // Iterate through objectsInPlay
        // Remove any that returns false for isDestroyed()
    
    
    return lives > 0;
}