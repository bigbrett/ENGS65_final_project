/*
 * Asteroid.cpp
 *
 * Code to implement Asteroid class
 *
 */

#include "Asteroid.h"

Asteroid::Asteroid()
: GameObject(AGT_ASTEROID, OBJ_DEFAULT_LOCATION,
             ASTEROID_BASE_SIZE * ASTEROID_DEFAULT_SIZE, OBJ_DEFAULT_ROTATION,
             ASTEROID_DEFAULT_SPEED, ASTEROID_DEFAULT_SPEED,
             ASTEROID_BASE_HEALTH * ASTEROID_DEFAULT_SIZE,
             ASTEROID_BASE_DAMAGE * ASTEROID_DEFAULT_SIZE),
            size(ASTEROID_DEFAULT_SIZE) {};

Asteroid::Asteroid(Asteroid_Size s, Point startLoc, int xDirectionSpeed,
         int yDirectionSpeed)
: GameObject(AGT_ASTEROID, startLoc, ASTEROID_BASE_SIZE * s,
             OBJ_DEFAULT_ROTATION, xDirectionSpeed, yDirectionSpeed,
             ASTEROID_BASE_HEALTH * ASTEROID_DEFAULT_SIZE,
             ASTEROID_BASE_DAMAGE * ASTEROID_DEFAULT_SIZE),
            size(ASTEROID_DEFAULT_SIZE) {};

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
    int offset = ASTEROID_BASE_SIZE * newSize / 2;
    Point p1(location.x, location.y+offset);
    Point p2(location.x, location.y-offset);
    Point p3(location.x+offset, location.y);
    Point p4(location.x-offset, location.y);
    
    Asteroid a1(newSize, p1, speedX, speedY+1);
    Asteroid a2(newSize, p2, speedX, speedY-1);
    Asteroid a3(newSize, p3, speedX+1, speedY);
    Asteroid a4(newSize, Point(location.x-offset, location.y), speedX-1, speedY);
    
    temp.push_back(&a1);
    temp.push_back(&a2);
    temp.push_back(&a3);
    temp.push_back(&a4);
    
    return temp;
}