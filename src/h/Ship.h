/*
 * Ship.h
 *
 * Ship class
 * Inherits from GameObject class
 *
 * Represents a ship (the player) on the game play field
 *
 */

#ifndef SHIP_H_
#define SHIP_H_

#include <SDL2/SDL.h>
#include <iostream>

#include "GameObject.h"
#include "Bullet.h"
#include "ShipGun.h"
#include "BigShipGun.h"

using namespace std;

class Ship: public GameObject
{
private:
    int lives;
    int shield;					// Damage reduction from collisions
    bool accelerate;
    ShipGun *gun;
    
public:
	Ship(int startingLives);
    Ship(const Ship& other);
    virtual ~Ship() {} // Nothing to destroy

	/* Overloaded Functions */
	void takeDmg(int dmg, Asteroid_GameObject_Type type);
    bool isDestroyed();
    void draw(SDL_Renderer* rend);
    
    /* Ship Specific Functions */

	// Shoot function
	// Returns a new Bullet object located at the front of the ship,
    // traveling in the direction the ship is pointing
	list<Bullet*> * shoot();
    
    // Rotate the ship 1 ANGLE_INC CW
    void rotateCW();
    
    // Rotate the ship 1 ANGLE_INC CCW
    void rotateCCW();
    
    // Set whether the ship should be accelerating or not
    void setAccelerate(bool accel);
    
    // Get remaining number of lives
    int getLives()
    {
        return lives;
    }
    
    // Upgrade the Ship's Gun
    void upgradeGun()
    {
        delete gun;
        gun = new BigShipGun();
    }
};

#endif /* SHIP_H_ */
