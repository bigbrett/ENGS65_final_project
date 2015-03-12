/*
 * Asteroid.cpp
 *
 * Code to implement Asteroid class
 *
 */

#include "Asteroid.h"


Asteroid::Asteroid(Asteroid_Size _size, SDL_Point location, int _x_velocity,
                   int _y_velocity)
        : GameObject(AGT_ASTEROID, location, _size * ASTEROID_BASE_SIZE,
            _size * ASTEROID_BASE_SIZE, OBJ_DEFAULT_ROTATION,
            _x_velocity, _y_velocity, _size * ASTEROID_BASE_HEALTH,
            _size * ASTEROID_BASE_DAMAGE)
{
    // Class Specific Variables
    size = _size;
}

Asteroid::Asteroid(const Asteroid& other) : GameObject(other)
{
    size = other.size;
}

void Asteroid::takeDmg(int dmg, Asteroid_GameObject_Type type)
{
    if(type == AGT_SHIP) health = 0;    // Make sure the ship kills the asteroid
    else if(type == AGT_ASTEROID)   {} // Do nothing if asteroids collide
    else health -= dmg;
}

list<GameObject*> * Asteroid::destroy()
{
    list<GameObject*> *temp = new list<GameObject*>();
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
    Asteroid *a1 = new Asteroid(newSize, p, x_velocity * size/newSize,
                                y_velocity * size/newSize + 1);
    
    p.x = collision_rect.x;
    p.y = collision_rect.y - offset;
    Asteroid *a2 = new Asteroid(newSize, p, x_velocity * size/newSize,
                                y_velocity * size/newSize - 1);
    
    p.x = collision_rect.x;
    p.y = collision_rect.y - offset;
    Asteroid *a3 = new Asteroid(newSize, p, x_velocity * size/newSize + 1,
                                y_velocity * size/newSize);
    
    p.x = collision_rect.x;
    p.y = collision_rect.y - offset;
    Asteroid *a4 = new Asteroid(newSize, p, x_velocity * size/newSize - 1,
                                y_velocity * size/newSize);
    
    temp->push_front((GameObject*) a1);
    temp->push_front((GameObject*) a2);
    temp->push_front((GameObject*) a3);
    temp->push_front((GameObject*) a4);
    
    return temp;
}