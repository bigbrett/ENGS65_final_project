//
//  ShipGun.cpp
//  Asteroids
//
//  Created by Dan Berman
//  Copyright (c) 2015 Dan Berman. All rights reserved.
//

#include "ShipGun.h"

list<Bullet*> * ShipGun::shoot(SDL_Point point, float trajectory)
{
    int x_vel = cos(trajectory) * BULLET_DEFAULT_SPEED;
    int y_vel = -sin(trajectory) * BULLET_DEFAULT_SPEED;
    
    Bullet *newBullet = new Bullet(point, x_vel , y_vel, BULLET_DEFAULT_DAMAGE);
    
    list<Bullet*> *temp = new list<Bullet*>;
    temp->push_front(newBullet);
    
    return temp;
}