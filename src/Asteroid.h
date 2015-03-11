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

#define ASTEROID_base_dmg 5

enum Asteroid_Size {AS_SMALL, AS_MED, AS_LARGE};

class Asteroid: public GameObject
{
	static SDL_Surface *image;	// The image used for the class
	Asteroid_Size size;
public:
	Asteroid();
	Asteroid(Asteroid_Size s);  // Initialize a new Asteroid object with given
                                // Asteroid_Size
	virtual ~Asteroid();
    
    /* Overloaded Functions */
    void takeDmg(int dmg, Asteroid_GameObject_Type type);
    list<GameObject*> destroy();
};

#endif /* ASTEROID_H_ */
