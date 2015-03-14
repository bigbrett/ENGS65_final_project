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
#include "Globals.h"


using namespace std;

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
    void draw(SDL_Renderer *rend);
};

#endif /* BULLET_H_ */
