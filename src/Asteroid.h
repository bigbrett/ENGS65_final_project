/*
 * Asteroid.h
 *
 *	Asteroid class
 *	Inherits from the GameObject class
 *
 *	Represents an asteroid on the game play field.
 */

#ifndef ASTEROID_H_
#define ASTEROID_H_

#include "GameObject.h"
#include <random>

#define ASTEROID_DEFAULT_SIZE   AS_LARGE
#define ASTEROID_BASE_SIZE      1
#define ASTEROID_BASE_HEALTH    1
#define ASTEROID_BASE_DAMAGE    2
#define ASTEROID_MAX_SPEED      9   // To scale speed based on size: speed/size

enum Asteroid_Size {AS_SMALL=1, AS_MED, AS_LARGE};

class Asteroid: public GameObject
{
	Asteroid_Size size;
public:
    Asteroid(Asteroid_Size _size, SDL_Point location, int _x_velocity,
             int _y_velocity);
    Asteroid(const Asteroid& other);
    virtual ~Asteroid() {};     // Nothing to delete
    
    /* Overloaded Functions */
    void takeDmg(int dmg, Asteroid_GameObject_Type type);
    list<GameObject*> * destroy();
};

#endif /* ASTEROID_H_ */
