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

#include "GameObject.h"
#include "Bullet.h"

class Ship: public GameObject
{
	static SDL_Surface *image;	// The image used for the class
	int shield;					// Shield to reduce the damage taken by colliding with other objects

public:
	Ship();
	virtual ~Ship();

	// Overloaded functions
    void move();
	void takeDmg(int dmg, Asteroid_GameObject_Type type);
    list<GameObject*> destroy();

	// Shoot function
	// Returns a new Bullet object located at the front of the ship, traveling in the direction the ship is pointing
	Bullet shoot();
    
    // Rotate 'increment' left (negative) or right (positive)
    void rotate(int increment);
    
    // Accelerate
    void accelerate();

};

#endif /* SHIP_H_ */
