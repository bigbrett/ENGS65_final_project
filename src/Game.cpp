/*
 * Game.cpp
 *
 * Code to implement Game class
 *
 */

#include "Game.h"

void checkCollisions();

Game::Game() {
	// TODO Auto-generated constructor stub

}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

bool Game::updateState(){
    /* User Input */
    // Check for WASD/Arrow keys pressed for ship movement
    
    // Check for SpaceBar press for firing
    
    /* Move() */
    
    /* Collisions */
    vector<GameObject*> damagedObjects;
    // Iterate through objectsInPlay, checking for collisions with remaining unchecked objects
    
        // If collision:
        // Add both to damagedObjects
        // call dmg() on both
    
    // Iterate through damagedObjects
        // Get object type
        // For bullet:
            // Delete object, remove from both vector sets
        // For ship:
            // If health zero
                // Decrement lives
                // Reset to starting location
        // For asteroid:
            // If health zero
                // Increase score
                // Delete object, remove from both vector sets
                // Add returned vector of new asteroids to objectsInPlay
    
    
    return lives > 0;
}