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
#include <list>
#include <cmath>
#include "Globals.h"

using namespace std;

class GameObject
{
protected:
	Asteroid_GameObject_Type objectType;	// Set to the type of GameObject
    SDL_Rect collision_rect;                // Object's collision rectangle
	float rotation;                         // Rotation of the object,
                                            // AD_N = 0 degrees of rotation
	int x_velocity;                         // +/- x speed
    int y_velocity;                         // +/- y speed
	int health;								// Current health
	int damage;								// Base damage the object does

    
    // Check for moving offscreen
    void movedOffScreen();
    
    
public:
    /* Constructors and Destructor */
    GameObject(Asteroid_GameObject_Type type, SDL_Point location, int height,
               int width, Asteroid_Direction _rotation, int _x_velocity,
               int _y_velocity, int _health, int _damage);
    
    GameObject(const GameObject& other) {
        objectType = other.objectType;
        collision_rect.x = other.collision_rect.x;
        collision_rect.y = other.collision_rect.y;
        collision_rect.h = other.collision_rect.h;
        collision_rect.w = other.collision_rect.w;
        rotation = other.rotation;
        x_velocity = other.x_velocity;
        y_velocity  = other.y_velocity;
        health = other.health;
        damage = other.damage;
    }
    
    virtual ~GameObject(){}
    
    /* Overloadable Operations */
    
	// Make the object move
    virtual void move();

	// Draw the object onto the game window surface
	// Doesn't do anything in this class
    virtual void draw(SDL_Renderer* rend){};

	// Damage the object from a collision
	virtual void takeDmg(int dmg, Asteroid_GameObject_Type type)
    {
        health -= dmg;
    }
    
    // Destroy the object; returns a list of new objects that replace it
    virtual list<GameObject*> * destroy()
    {
        list<GameObject*> *temp = new list<GameObject*>();
        return temp;
    }
    
    /* Standard functions */
    
    // See if the object is destroyed
    bool isDestroyed()
    {
        return health<=0;
    }

	/* Getters */
	Asteroid_GameObject_Type getObjectType()
    {
        return objectType;
    }
    
	int getDamage()
    {
        return damage;
    }
};

#endif /* GAMEOBJECT_H_ */
