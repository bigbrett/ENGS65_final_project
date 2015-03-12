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
    objectsInPlay.push_front(ship);
    for(int i = 0; i < startingNumAsteroids; i++)
    {
        Asteroid *temp = new Asteroid();
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
    list<GameObject*> damagedObjects;
    // Iterate through objectsInPlay, checking for collisions
    
        // If collision:
            // call dmg() on both
    // Iterate through objectsInPlay
        // Remove any that returns false for isDestroyed()
    
    
    return lives > 0;
}