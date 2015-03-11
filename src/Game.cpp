/*
 * Game.cpp
 *
 * Code to implement Game class
 *
 */

#include "Game.h"


Game::Game(): lives(DEFAULT_NUM_LIVES), score(0)
{
    objectsInPlay.push_front(ship);
    for(int i = 0; i < DEFAULT_NUM_ASTEROIDS; i++)
    {
        Asteroid *temp = new Asteroid();
        objectsInPlay.push_back(temp);
    }
}

Game::Game(int startingNumAsteroids, int startingLives, int startingScore) : lives(startingLives), score(startingScore)
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

bool Game::updateState()
{
    /* User Input */
    // Check for WASD/Arrow keys pressed for ship movement
        // W/UpArrow -> call accelerate on ship
        // A/LArrow -> ship.rotate(-)
        // D/RArrow -> ship.rotate(+)
        
    
    // Check for SpaceBar press for firing -> ship.fire()
    
    /* Move() */
    
    /* Collisions */
    list<GameObject*> damagedObjects;
    // Iterate through objectsInPlay, checking for collisions with remaining unchecked objects
    
        // If collision:
        // Add both to damagedObjects
        // *** What if one has already been added from collision with prior object? ***
        // *** Just iterate and confirm not already in damagedObjects before adding? ***
        // call dmg() on both
    
    // Iterate through damagedObjects
        // Get object type
        // For bullet:
            // Delete object, remove from both lists
        // For ship:
            // If health zero
                // Decrement lives
                // Reset to starting location
        // For asteroid:
            // If health zero
                // Increase score
                // Delete object, remove from both vector sets
                // Add returned list of new asteroids to objectsInPlay
    
    
    return lives > 0;
}