/*
 * GameObject.h
 *
 * GameObject class
 *
 * Is a parent class for the different types of objects used in the Asteroids 
 * game to inherit from.
 *
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <SDL2/SDL.h>
#include <cstdlib>
#include <string>
#include "AsteroidGlobals.h"
#include <list>

#define OBJ_DEFAULT_LOCATION    Point(-1,-1)
#define OBJ_DEFAULT_SIZE        -1
#define OBJ_DEFAULT_ROTATION    AD_SIZE
#define OBJ_DEFAULT_SPEED       -1
#define OBJ_DEFAULT_HEALTH      -1
#define OBJ_DEFAULT_DAMAGE      0

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
	Point startLocation;					// Starting location
    Point location;							// Current location
	int edgeLength;							// Objects are squares
	Asteroid_Direction rotation;			// Rotation of the object,
                                            // AD_N = 0 degrees of rotation
	int speedX;                             // +/- x speed
    int speedY;                             // +/- y speed
	int health;								// Current health
	int damage;								// Base damage the object does

public:
    /* Constructors and Destructor */ 
    GameObject()
    : objectType(AGT_GAMEOBJECT),startLocation(OBJ_DEFAULT_LOCATION),
    location(OBJ_DEFAULT_LOCATION), edgeLength(OBJ_DEFAULT_SIZE),
    rotation(OBJ_DEFAULT_ROTATION), speedX(OBJ_DEFAULT_SPEED),
    speedY(OBJ_DEFAULT_SPEED), health(OBJ_DEFAULT_HEALTH),
    damage(OBJ_DEFAULT_DAMAGE) {};
    
    GameObject(Asteroid_GameObject_Type type, Point startLoc, int edgeLength,
               Asteroid_Direction _rotation, int xSpeed, int ySpeed,
               int _health, int _damage)
    : objectType(type), startLocation(startLoc), location(startLoc),
    edgeLength(edgeLength), rotation(_rotation), speedX(xSpeed), speedY(ySpeed),
    health(_health), damage(_damage) {};
    
    virtual ~GameObject(){delete &startLocation; delete &location;};

	// Make the object move
	virtual void move(){location.x = location.x + speedX;
        location.y = location.y + speedY;};

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
