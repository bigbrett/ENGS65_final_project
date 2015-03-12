/*
 * Asteroid.cpp
 *
 * Code to implement Asteroid class
 *
 */

#include "Asteroid.h"

Asteroid::Asteroid()
{
    // Class Specific Variables
    size = ASTEROID_DEFAULT_SIZE;
    
    // Parent Variables
    objectType = AGT_ASTEROID;
    collision_rect.x = OBJ_DEFAULT_LOCATION;
    collision_rect.y = OBJ_DEFAULT_LOCATION;
    collision_rect.h = size * ASTEROID_BASE_SIZE;
    collision_rect.w = size * ASTEROID_BASE_SIZE;
    rotation = OBJ_DEFAULT_ROTATION;
    x_velocity = OBJ_DEFAULT_SPEED;
    y_velocity = OBJ_DEFAULT_SPEED;
    health = size * ASTEROID_BASE_HEALTH;
    damage = size * ASTEROID_BASE_DAMAGE;
}

Asteroid::Asteroid(Asteroid_Size _size, SDL_Point location, int _x_velocity,
                   int _y_velocity)
{
    // Class Specific Variables
    size = _size;
    
    // Parent Variables
    objectType = AGT_ASTEROID;
    collision_rect.x = location.x;
    collision_rect.y = location.y;
    collision_rect.h = size * ASTEROID_BASE_SIZE;
    collision_rect.w = size * ASTEROID_BASE_SIZE;
    rotation = OBJ_DEFAULT_ROTATION;
    x_velocity = _x_velocity;
    y_velocity = _y_velocity;
    health = size * ASTEROID_BASE_HEALTH;
    damage = size * ASTEROID_BASE_DAMAGE;
}

Asteroid::Asteroid(const Asteroid& other) : GameObject(other)
{
    size = other.size;
}

void Asteroid::takeDmg(int dmg, Asteroid_GameObject_Type type)
{
    if(type == AGT_SHIP) health = 0;    // Make sure the ship kills the asteroid
    else health -= dmg;
}

list<GameObject*> Asteroid::destroy()
{
    list<GameObject*> temp;
    Asteroid_Size newSize;
    if (size == AS_LARGE) newSize = AS_MED;
    else if (size == AS_MED) newSize = AS_SMALL;
    else return temp;
    
    // Create 4 new asteroids around the old one
    // Add 1 to the velocity in the direction of the offset in case velocity
    // in that direction currently is 0, to ensure movement.
    int offset = ASTEROID_BASE_SIZE * newSize / 2;
    SDL_Point p;
    
    p.x = collision_rect.x;
    p.y = collision_rect.y + offset;
    Asteroid *a1 = new Asteroid(newSize, p, x_velocity, y_velocity + 1);
    
    p.x = collision_rect.x;
    p.y = collision_rect.y - offset;
    Asteroid *a2 = new Asteroid(newSize, p, x_velocity, y_velocity - 1);
    
    p.x = collision_rect.x;
    p.y = collision_rect.y - offset;
    Asteroid *a3 = new Asteroid(newSize, p, x_velocity + 1, y_velocity);
    
    p.x = collision_rect.x;
    p.y = collision_rect.y - offset;
    Asteroid *a4 = new Asteroid(newSize, p, x_velocity - 1, y_velocity);
    
    temp.push_front((GameObject*) a1);
    temp.push_front((GameObject*) a2);
    temp.push_front((GameObject*) a3);
    temp.push_front((GameObject*) a4);
    
    return temp;
}