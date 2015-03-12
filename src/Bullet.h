/*
 * Bullet.h
 *
 *	Bullet Class
 *	Inherits from GameObject class
 *
 *	Represents a bullet on the game play field
 *
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "GameObject.h"

#define BULLET_DEFAULT_DAMAGE   1
#define BULLET_DEFAULT_SIZE     1


class Bullet: public GameObject
{
public:
	Bullet();
    Bullet(SDL_Point location, int _x_velocity, int _y_velocity, int _damage);
    virtual ~Bullet() {}; // Nothing to destroy
    
    /* Overloaded functions */
    // None
};

#endif /* BULLET_H_ */
