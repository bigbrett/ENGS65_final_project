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
    uniform_int_distribution<int> v_gen (0, ASTEROID_MAX_SPEED);
    
    // Put the ship into the list
    objectsInPlay.push_front(ship);
    
    // Add the asteroids in
    for(int i = 0; i < startingNumAsteroids; i++)
    {
        SDL_Point p;
        p.x = x_gen(generator);
        p.y = y_gen(generator);
        Asteroid *temp = new Asteroid(ASTEROID_DEFAULT_SIZE, p,
                                      v_gen(generator)/ASTEROID_DEFAULT_SIZE,
                                      v_gen(generator)/ASTEROID_DEFAULT_SIZE);
        objectsInPlay.push_back(temp);
    }
};

Game::~Game()
{
	// TODO

}

void Game::handleEvent(SDL_Event &e)
{
    // Check for Key Press
    if(e.type == SDL_KEYDOWN || e.type == SDL_KEYUP){
        ship->handleKeyboardEvent(e);
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