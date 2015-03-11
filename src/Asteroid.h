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

class Asteroid: public GameObject {
	static SDL_Surface *image;	// The image used for the class
	static bool init;			// See if the class has been initialized
	Asteroid_Size size;
public:
	Asteroid();
	Asteroid(Asteroid_Size s); // Initialize a new Asteroid object with given Asteroid_Size
	virtual ~Asteroid();
};

#endif /* ASTEROID_H_ */
