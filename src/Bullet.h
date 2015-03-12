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
#define BULLET_DEFAULT_HEALTH   1
#define BULLET_DEFAULT_SPEED    3
#define BULLET_MAX_DISTANCE     100


class Bullet: public GameObject
{
    int distance_traveled;  // How far the bullet has gone. Bullet dies after
                            // traveling BULLET_MAX_DISTANCE
public:
    Bullet(SDL_Point location, int _x_velocity, int _y_velocity, int _damage);
    Bullet(const Bullet& other);
    virtual ~Bullet() {};  // Nothing to destroy
    
    /* Overloaded functions */
    void move();    // Overloaded for distance_traveled and becaues bullets
                    // don't screen-wrap, so no movedOffScreen() call
};

#endif /* BULLET_H_ */
