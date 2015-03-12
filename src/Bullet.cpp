/*
 * Bullet.cpp
 *
 *	Code to implement the Bullet class
 *
 */

#include "Bullet.h"

#define BULLET_HEALTH 1

Bullet::Bullet()
{
    objectType = AGT_BULLET;
    collision_rect.x = OBJ_DEFAULT_LOCATION;
    collision_rect.y = OBJ_DEFAULT_LOCATION;
    collision_rect.h = BULLET_DEFAULT_SIZE;
    collision_rect.w = BULLET_DEFAULT_SIZE;
    rotation = OBJ_DEFAULT_ROTATION;
    x_velocity = OBJ_DEFAULT_SPEED;
    y_velocity = OBJ_DEFAULT_SPEED;
    health = OBJ_DEFAULT_HEALTH;
    damage = BULLET_DEFAULT_DAMAGE;
}

Bullet::Bullet(SDL_Point location, int _x_velocity, int _y_velocity, int _damage)
{
    objectType = AGT_BULLET;
    collision_rect.x = location.x;
    collision_rect.y = location.y;
    collision_rect.h = BULLET_DEFAULT_SIZE;
    collision_rect.w = BULLET_DEFAULT_SIZE;
    rotation = OBJ_DEFAULT_ROTATION;
    x_velocity = _x_velocity;
    y_velocity = _y_velocity;
    health = OBJ_DEFAULT_HEALTH;
    damage = _damage;
}