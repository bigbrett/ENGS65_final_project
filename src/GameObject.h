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
#include <list>

using namespace std;



class GameObject
{
protected:
    struct Point
    {
        int x;
        int y;
        
        Point(){};
        Point(int x, int y) : x(x), y(y) {};
    };
    
    /* Variables are all protected, to allow children access */
	Asteroid_GameObject_Type objectType;	// Set to the type of GameObject
	Point startLocation;					// Location that the object starts at/resets to
    Point location;							// Location of the center of the object
	int edgeSize;							// Objects are squares of size edgeSize; must be an odd value!!
	Asteroid_Direction rotation;			// Rotation of the object, AD_N = 0 degrees of rotation
	int speedX;                             // Speed at which the object is currently moving, in +/- x
    int speedY;                             // Speed at which the object is currently moving, in +/- y
	int health;								// Objects health
	int damage;								// Base damage the object does when colliding with another

public:
    GameObject():objectType(AGT_GAMEOBJECT), startLocation(-1,-1), location(-1,-1), edgeSize(-1), rotation(AD_SIZE),
                speedX(0), speedY(0), health(0), damage(0) {};
    GameObject(Asteroid_GameObject_Type type, Point startLoc, int edgeLength, Asteroid_Direction _rotation,
               int xSpeed, int ySpeed, int _health, int _damage):objectType(type), startLocation(startLoc),
                location(startLoc), edgeSize(edgeLength), rotation(_rotation), speedX(xSpeed), speedY(ySpeed),
                health(_health), damage(_damage){};
    virtual ~GameObject(){delete &startLocation; delete &location;};

	// Make the object move
	virtual void move(){location.x = location.x + speedX; location.y = location.y + speedY;};

	// Draw the object onto the game window surface
	// Doesn't do anything in this class
	virtual void draw(SDL_Surface *gameWindow){};

	// Reset the object back to its starting location
	void resetLocation(){location = startLocation;};

	// Damage the object from a collision
	virtual void takeDmg(int dmg, Asteroid_GameObject_Type type){health -= dmg;};
    
    // Destroy the object; returns a list of new objects that replace it
    virtual list<GameObject*> destroy(){return list<GameObject*>();};
    
    // See if the object is destroyed
    bool isDestroyed(){return health<=0;};

	/* Getters */
	Asteroid_GameObject_Type getObjectType(){return objectType;};
	int getDamage(){return damage;};
};

#endif /* GAMEOBJECT_H_ */
