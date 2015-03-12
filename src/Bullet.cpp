/*
 * Bullet.cpp
 *
 *	Code to implement the Bullet class
 *
 */

#include "Bullet.h"

Bullet::Bullet(SDL_Point location, int _x_velocity, int _y_velocity, int _damage)
        : GameObject(AGT_BULLET, location, BULLET_DEFAULT_SIZE,
                     BULLET_DEFAULT_SIZE, OBJ_DEFAULT_ROTATION, _x_velocity,
                     _y_velocity, BULLET_DEFAULT_HEALTH, _damage)
{
    // Class Specific Variables
    distance_traveled = 0;
}

Bullet::Bullet(const Bullet& other) : GameObject(other)
{
    distance_traveled = other.distance_traveled;
}

void Bullet::move(){
    collision_rect.x += x_velocity;
    collision_rect.y += y_velocity;
    distance_traveled += sqrt(x_velocity^2 + y_velocity^2);
    
    if (distance_traveled >= BULLET_MAX_DISTANCE) {
        health = 0;
    }
}