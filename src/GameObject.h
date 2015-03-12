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
#include "Texture.h"

#define PI 3.14159

#define OBJ_DEFAULT_LOCATION    -1
#define OBJ_DEFAULT_SIZE        -1
#define OBJ_DEFAULT_ROTATION    AD_SIZE
#define OBJ_DEFAULT_SPEED       0
#define OBJ_DEFAULT_HEALTH      -1
#define OBJ_DEFAULT_DAMAGE      0

enum Asteroid_GameObject_Type
{
    AGT_GAMEOBJECT, AGT_SHIP, AGT_BULLET, AGT_ASTEROID
};

enum Asteroid_Direction
{
    AD_N, AD_NNE, AD_NE, AD_ENE, AD_E, AD_ESE, AD_SE, AD_SSE, AD_S, AD_SSW,
    AD_SW, AD_WSW, AD_W, AD_WNW, AD_NW, AD_NNW, AD_SIZE
};

using namespace std;

class GameObject
{
protected:
	Asteroid_GameObject_Type objectType;	// Set to the type of GameObject
    SDL_Rect collision_rect;                // Object's collision rectangle
	Asteroid_Direction rotation;			// Rotation of the object,
                                            // AD_N = 0 degrees of rotation
	int x_velocity;                         // +/- x speed
    int y_velocity;                         // +/- y speed
	int health;								// Current health
	int damage;								// Base damage the object does

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;
    
    //The window renderer
    SDL_Renderer* gRenderer = NULL;
    
    //Scene textures
    Texture gTexture;
    
    
public:
    /* Constructors and Destructor */ 
    GameObject()
    {
        objectType = AGT_GAMEOBJECT;
        collision_rect.x = OBJ_DEFAULT_LOCATION;
        collision_rect.y = OBJ_DEFAULT_LOCATION;
        collision_rect.h = OBJ_DEFAULT_SIZE;
        collision_rect.w = OBJ_DEFAULT_SIZE;
        rotation = OBJ_DEFAULT_ROTATION;
        x_velocity = OBJ_DEFAULT_SPEED;
        y_velocity = OBJ_DEFAULT_SPEED;
        health = OBJ_DEFAULT_HEALTH;
        damage = OBJ_DEFAULT_DAMAGE;
    };
    
    GameObject(Asteroid_GameObject_Type type, SDL_Point location,
               Asteroid_Direction _rotation, int _x_velocity, int _y_velocity,
               int _health, int _damage)
    {
        objectType = type;
        collision_rect.x = OBJ_DEFAULT_LOCATION;
        collision_rect.y = OBJ_DEFAULT_LOCATION;
        collision_rect.h = OBJ_DEFAULT_SIZE;
        collision_rect.w = OBJ_DEFAULT_SIZE;
        rotation = _rotation;
        x_velocity = _x_velocity;
        y_velocity = _y_velocity;
        health = _health;
        damage = _damage;
    };
    
    virtual GameObject(const GameObject& other) {
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
    
    virtual ~GameObject(){delete &location;};
    
    /* Overloadable Operations */
    
	// Make the object move
	virtual void move()
    {
        collision_rect.x += x_velocity;
        collision_rect.y += y_velocity;
    };

	// Draw the object onto the game window surface
	// Doesn't do anything in this class
	virtual void draw(SDL_Surface *gameWindow){};

	// Damage the object from a collision
	virtual void takeDmg(int dmg, Asteroid_GameObject_Type type)
    {
        health -= dmg;
    };
    
    // Destroy the object; returns a list of new objects that replace it
    virtual list<GameObject*> destroy()
    {
        return list<GameObject*>();
    };
    
    /* Standard functions */
    
    // See if the object is destroyed
    bool isDestroyed()
    {
        return health<=0;
    };

	/* Getters */
	Asteroid_GameObject_Type getObjectType()
    {
        return objectType;
    };
    
	int getDamage()
    {
        return damage;
    };
};

#endif /* GAMEOBJECT_H_ */
