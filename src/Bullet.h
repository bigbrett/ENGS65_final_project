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

#define BULLET_DEFAULT_DAMAGE 1
#define BULLET_DEFAULT_SPEED 1


class Bullet: public GameObject
{
public:
	Bullet();
    Bullet(Point startLoc, int xDirectionSpeed, int yDirectionSpeed,
           int _health, int _damage);
    virtual ~Bullet() {}; // Nothing to destroy
    
    /* Overloaded functions */
    
};

#endif /* BULLET_H_ */
