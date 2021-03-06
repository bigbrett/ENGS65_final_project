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
    distance_traveled += sqrt(pow(x_velocity, 2) + pow(y_velocity,2));
    
    if (distance_traveled >= BULLET_MAX_DISTANCE) {
        health = 0;
    }
}

void Bullet::draw(SDL_Renderer *rend)
{
    SDL_SetRenderDrawColor(rend, 0,255,255, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(rend, &collision_rect);
}