//
//  BigShipGun.cpp
//  Asteroids
//
//  Created by Dan Berman
//  Copyright (c) 2015 Dan Berman. All rights reserved.
//

#include "BigShipGun.h"

list<Bullet*> * BigShipGun::shoot(SDL_Point point, float trajectory)
{
    
    list<Bullet*> *temp = new list<Bullet*>;
    
    // Creates 3 bullets, that spray out around the trajectory given
    
    for (int i = -1; i <= 1; i++)
    {
        int x_vel = cos(trajectory + ANGLE_INC * i) * BULLET_DEFAULT_SPEED;
        int y_vel = -sin(trajectory + ANGLE_INC * i) * BULLET_DEFAULT_SPEED;
        
        Bullet *newBullet = new Bullet(point, x_vel , y_vel, BULLET_DEFAULT_DAMAGE);
        temp->push_front(newBullet);
    }
    
    return temp;
}