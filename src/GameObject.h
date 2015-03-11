/*
 * GameObject.h
 *
 * GameObject class
 *
 * Is a parent class for the different types of objects used in the Asteroids game to inherit from.
 *
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <SDL2/SDL.h>
#include <cstdlib>
#include <string>
#include "AsteroidGlobals.h"

//using namespace std;

class GameObject
{
protected:	/* Variables are all protected, to allow children access */
	Asteroid_GameObject_Type objectType;	// Set to the type of GameObject
	Point location;							// Location of the center of the object
	Point startLocation;					// Location that the object starts at/resets to
	int edgeSize;							// Objects are squares of size edgeSize; must be an odd value!!
	Asteroid_Direction rotation;			// Rotation of the object, AD_N = 0 degrees of rotation
	Point speed;							// Speed at which the object is currently moving, in +/- x and +/- y
	int health;								// Objects health
	int damage;								// Base damage the object does when colliding with another

public:
	GameObject();
	virtual ~GameObject();

	// Make the object move
	virtual void move(){location.x = location.x + speed.x; location.y = location.y + speed.y;};

	// Have the object accelerate
	// Doesn't do anything in this class
	virtual void accelerate(){};

	// Draw the object onto the game window surface
	// Doesn't do anything in this class
	virtual void draw(SDL_Surface *gameWindow){};

	// Reset the object back to its starting location
	void resetLocation(){location = startLocation;};

	// Damage the object from a collision
	virtual int takeDmg(int dmg, Asteroid_GameObject_Type type){health -= dmg; return health;};

	/* Getters */
	Asteroid_GameObject_Type getObjectType(){return objectType;};
	Point getCurrPosition(){return location;};
	int getCurrSize(){return edgeSize;};
	Asteroid_Direction getCurrRotation(){return rotation;};
	Point getCurrSpeed(){return speed;};
	int getDamage(){return damage;};
};

#endif /* GAMEOBJECT_H_ */
