/*
 * Asteroid.cpp
 *
 * Code to implement Asteroid class
 *
 */

#include "Asteroid.h"

int Asteroid::numAsteroids = 0;

Asteroid::Asteroid(Asteroid_Size _size, SDL_Point location, int _x_velocity,
                   int _y_velocity)
        : GameObject(AGT_ASTEROID, location, _size * ASTEROID_BASE_SIZE,
            _size * ASTEROID_BASE_SIZE, OBJ_DEFAULT_ROTATION,
            _x_velocity, _y_velocity, _size * ASTEROID_BASE_HEALTH,
            _size * ASTEROID_BASE_DAMAGE)
{
    // Class Specific Variables
    size = _size;
    numAsteroids++;
}

Asteroid::Asteroid(const Asteroid& other) : GameObject(other)
{
    size = other.size;
}

void Asteroid::takeDmg(int dmg, Asteroid_GameObject_Type type)
{
    if(type == AGT_SHIP) health = 0;    // Make sure the ship kills the asteroid
    else if(type == AGT_ASTEROID);      // Do nothing if asteroids collide
    else health -= dmg;
}

list<GameObject*> * Asteroid::destroy()
{
    list<GameObject*> *temp = new list<GameObject*>;
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
    Asteroid *a1 = new Asteroid(newSize, p, x_velocity,
                                y_velocity + 1);
    
    p.x = collision_rect.x;
    p.y = collision_rect.y - offset;
    Asteroid *a2 = new Asteroid(newSize, p, x_velocity,
                                y_velocity - 1);
    
    p.x = collision_rect.x;
    p.y = collision_rect.y - offset;
    Asteroid *a3 = new Asteroid(newSize, p, x_velocity + 1,
                                y_velocity);
    
    p.x = collision_rect.x;
    p.y = collision_rect.y - offset;
    Asteroid *a4 = new Asteroid(newSize, p, x_velocity - 1,
                                y_velocity);
    
    temp->push_front(a1);
    temp->push_front(a2);
    temp->push_front(a3);
    temp->push_front(a4);
    
    return temp;
}

/*
 * Draw an asteroid
 */
void Asteroid::draw(SDL_Renderer* rend)
{
    float cosA = cos(rotation);
    float sinA = sin(rotation);
    
    SDL_Point* lines = new SDL_Point[10];
    SDL_Rect pos = collision_rect;
    pos.x = pos.x + pos.w / 2;  // Move coordinates to center of the rectangle
    pos.y = pos.y + pos.h / 2;
    
    
    float a = 1.5;
    float ten = a*pos.w/10;
    float fifteen = a*pos.w/6.66;
    float twenty = a*pos.w/5;
    float thirty = a*pos.w/3.33;
    float thirtyfive = a*pos.w/2.85;
    float fourty = a*pos.w/3.33;
    float fourtyfive = a*pos.w/2.5;
    float fifty = a*pos.w/2;
    
    lines[0] = {int(cosA *  1  - sinA * -fifty + pos.x),
                int(sinA *  1  + cosA * -fifty + pos.y)};
    
    lines[1] = {int(cosA *  thirty - sinA * -fourty + pos.x),
                int(sinA *  thirty + cosA * -fourty + pos.y)};
    
    lines[2] = {int(cosA *  fifty - sinA * -ten + pos.x),
                int(sinA *  fifty + cosA * -ten + pos.y)};
    
    lines[3] = {int(cosA *  thirtyfive - sinA * twenty + pos.x),
                int(sinA *  thirtyfive + cosA * twenty + pos.y)};
    
    lines[4] = {int(cosA *  fifteen - sinA * fifty + pos.x),
                int(sinA *  fifteen + cosA * fifty + pos.y)};
    
    lines[5] = {int(cosA * -ten - sinA * fourtyfive + pos.x),
                int(sinA * -ten + cosA * fourtyfive + pos.y)};
    
    lines[6] = {int(cosA * -fourty - sinA * fourty + pos.x),
                int(sinA * -fourty + cosA * fourty + pos.y)};
    
    lines[7] = {int(cosA * -thirty - sinA * -ten + pos.x),
                int(sinA * -thirty + cosA * -ten + pos.y)};
    
    lines[8] = {int(cosA * -ten - sinA * -fifteen + pos.x),
                int(sinA * -ten + cosA * -fifteen + pos.y)};
    
    lines[9] = {int(cosA *  1  - sinA * -fifty + pos.x),
                int(sinA *  1  + cosA * -fifty + pos.y)};
    
    // Render and draw
    SDL_SetRenderDrawColor(rend, 255,255,255, 255);
    SDL_RenderDrawLines(rend, lines, 10);
}

