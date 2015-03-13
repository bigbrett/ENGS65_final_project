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

#include <random>

#include "GameObject.h"
#include "Globals.h"

using namespace std;

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
