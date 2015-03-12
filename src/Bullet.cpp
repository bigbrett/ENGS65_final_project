/*
 * Bullet.cpp
 *
 *	Code to implement the Bullet class
 *
 */

#include "Bullet.h"

Bullet::Bullet()
{
    // Class Specific Variables
    distance_traveled = 0;
    
    // Parent Variables
    objectType = AGT_BULLET;
    collision_rect.x = OBJ_DEFAULT_LOCATION;
    collision_rect.y = OBJ_DEFAULT_LOCATION;
    collision_rect.h = BULLET_DEFAULT_SIZE;
    collision_rect.w = BULLET_DEFAULT_SIZE;
    rotation = OBJ_DEFAULT_ROTATION;
    x_velocity = OBJ_DEFAULT_SPEED;
    y_velocity = OBJ_DEFAULT_SPEED;
    health = BULLET_DEFAULT_HEALTH;
    damage = BULLET_DEFAULT_DAMAGE;
}

Bullet::Bullet(SDL_Point location, int _x_velocity, int _y_velocity, int _damage)
{
    // Class Specific Variables
    distance_traveled = 0;
    
    // Parent Variables
    objectType = AGT_BULLET;
    collision_rect.x = location.x;
    collision_rect.y = location.y;
    collision_rect.h = BULLET_DEFAULT_SIZE;
    collision_rect.w = BULLET_DEFAULT_SIZE;
    rotation = OBJ_DEFAULT_ROTATION;
    x_velocity = _x_velocity;
    y_velocity = _y_velocity;
    health = BULLET_DEFAULT_HEALTH;
    damage = _damage;
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