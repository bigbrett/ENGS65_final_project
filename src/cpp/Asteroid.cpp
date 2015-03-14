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
    
    switch (size)
    {
        case AS_LARGE:
            lines[0] = { int(cosA * (pos.x - pos.x) - sinA * (pos.y - 50 - pos.y) + pos.x),
                int(sinA * (pos.x - pos.x) + cosA * (pos.y - 50 - pos.y) + pos.y) };
            
            
            lines[1] = { int(cosA * (pos.x + 30 - pos.x) - sinA * (pos.y - 40 - pos.y) + pos.x),
                int(sinA * (pos.x + 30 - pos.x) + cosA * (pos.y - 40 - pos.y) + pos.y) };
            
            lines[2] = { int(cosA * (pos.x + 50 - pos.x) - sinA * (pos.y - 10 - pos.y) + pos.x),
                int(sinA * (pos.x + 50 - pos.x) + cosA * (pos.y - 10 - pos.y) + pos.y) };
            
            lines[3] = { int(cosA * (pos.x + 35 - pos.x) - sinA * (pos.y + 20 - pos.y) + pos.x),
                int(sinA * (pos.x + 35 - pos.x) + cosA * (pos.y + 20 - pos.y) + pos.y) };
            
            lines[4] = { int(cosA * (pos.x + 15 - pos.x) - sinA * (pos.y + 50 - pos.y) + pos.x),
                int(sinA * (pos.x + 15 - pos.x) + cosA * (pos.y + 50 - pos.y) + pos.y) };
            
            lines[5] = { int(cosA * (pos.x - 10 - pos.x) - sinA * (pos.y + 45 - pos.y) + pos.x),
                int(sinA * (pos.x - 10 - pos.x) + cosA * (pos.y + 45 - pos.y) + pos.y) };
            
            lines[6] = { int(cosA * (pos.x - 40 - pos.x) - sinA * (pos.y + 40 - pos.y) + pos.x),
                int(sinA * (pos.x - 40 - pos.x) + cosA * (pos.y + 40 - pos.y) + pos.y) };
            
            lines[7] = { int(cosA * (pos.x - 30 - pos.x) - sinA * (pos.y - 10 - pos.y) + pos.x),
                int(sinA * (pos.x - 30 - pos.x) + cosA * (pos.y - 10 - pos.y) + pos.y) };
            
            lines[8] = { int(cosA * (pos.x - 10 - pos.x) - sinA * (pos.y - 15 - pos.y) + pos.x),
                int(sinA * (pos.x - 10 - pos.x) + cosA * (pos.y - 15 - pos.y) + pos.y) };
            
            lines[9] = { int(cosA * (pos.x - pos.x) - sinA * (pos.y - 50 - pos.y) + pos.x),
                int(sinA * (pos.x - pos.x) + cosA * (pos.y - 50 - pos.y) + pos.y) };
            break;
            
        case AS_MED:
            lines[0] = { int(cosA * (pos.x - pos.x) - sinA * (pos.y - 25 - pos.y) + pos.x),
                int(sinA * (pos.x - pos.x) + cosA * (pos.y - 25 - pos.y) + pos.y) };
            
            lines[1] = { int(cosA * (pos.x + 20 - pos.x) - sinA * (pos.y - 40 - pos.y) + pos.x),
                int(sinA * (pos.x + 20 - pos.x) + cosA * (pos.y - 40 - pos.y) + pos.y) };
            
            lines[2] = { int(cosA * (pos.x + 30 - pos.x) - sinA * (pos.y - 10 - pos.y) + pos.x),
                int(sinA * (pos.x + 30 - pos.x) + cosA * (pos.y - 10 - pos.y) + pos.y) };
            
            lines[3] = { int(cosA * (pos.x + 30 - pos.x) - sinA * (pos.y + 15 - pos.y) + pos.x),
                int(sinA * (pos.x + 30 - pos.x) + cosA * (pos.y + 15 - pos.y) + pos.y) };
            
            lines[4] = { int(cosA * (pos.x + 15 - pos.x) - sinA * (pos.y + 30 - pos.y) + pos.x),
                int(sinA * (pos.x + 15 - pos.x) + cosA * (pos.y + 30 - pos.y) + pos.y) };
            
            lines[5] = { int(cosA * (pos.x - 10 - pos.x) - sinA * (pos.y + 25 - pos.y) + pos.x),
                int(sinA * (pos.x - 10 - pos.x) + cosA * (pos.y + 25 - pos.y) + pos.y) };
            
            lines[6] = { int(cosA * (pos.x - 25 - pos.x) - sinA * (pos.y + 25 - pos.y) + pos.x),
                int(sinA * (pos.x - 25 - pos.x) + cosA * (pos.y + 25 - pos.y) + pos.y) };
            
            lines[7] = { int(cosA * (pos.x - 25 - pos.x) - sinA * (pos.y - 10 - pos.y) + pos.x),
                int(sinA * (pos.x - 25 - pos.x) + cosA * (pos.y - 10 - pos.y) + pos.y) };
            
            lines[8] = { int(cosA * (pos.x - 10 - pos.x) - sinA * (pos.y - 15 - pos.y) + pos.x),
                int(sinA * (pos.x - 10 - pos.x) + cosA * (pos.y - 15 - pos.y) + pos.y) };
            
            lines[9] = { int(cosA * (pos.x - pos.x) - sinA * (pos.y - 25 - pos.y) + pos.x),
                int(sinA * (pos.x - pos.x) + cosA * (pos.y - 25 - pos.y) + pos.y) };
            
            break;
            
        case AS_SMALL:
            lines[0] = { int(cosA * (pos.x - pos.x) - sinA * (pos.y - 10 - pos.y) + pos.x),
                int(sinA * (pos.x - pos.x) + cosA * (pos.y - 10 - pos.y) + pos.y) };
            
            lines[1] = { int(cosA * (pos.x + 8 - pos.x) - sinA * (pos.y - 3 - pos.y) + pos.x),
                int(sinA * (pos.x + 8 - pos.x) + cosA * (pos.y - 3 - pos.y) + pos.y) };
            
            lines[2] = { int(cosA * (pos.x + 3 - pos.x) - sinA * (pos.y - 0 - pos.y) + pos.x),
                int(sinA * (pos.x + 3 - pos.x) + cosA * (pos.y - 0 - pos.y) + pos.y) };
            
            lines[3] = { int(cosA * (pos.x + 5 - pos.x) - sinA * (pos.y + 8 - pos.y) + pos.x),
                int(sinA * (pos.x + 5 - pos.x) + cosA * (pos.y + 8 - pos.y) + pos.y) };
            
            lines[4] = { int(cosA * (pos.x + 8 - pos.x) - sinA * (pos.y + 13 - pos.y) + pos.x),
                int(sinA * (pos.x + 8 - pos.x) + cosA * (pos.y + 13 - pos.y) + pos.y) };
            
            lines[5] = { int(cosA * (pos.x - 8 - pos.x) - sinA * (pos.y + 18 - pos.y) + pos.x),
                int(sinA * (pos.x - 8 - pos.x) + cosA * (pos.y + 18 - pos.y) + pos.y) };
            
            lines[6] = { int(cosA * (pos.x - 13 - pos.x) - sinA * (pos.y + 3 - pos.y) + pos.x),
                int(sinA * (pos.x - 13 - pos.x) + cosA * (pos.y + 3 - pos.y) + pos.y) };
            
            lines[7] = { int(cosA * (pos.x - 8 - pos.x) - sinA * (pos.y - 3 - pos.y) + pos.x),
                int(sinA * (pos.x - 8 - pos.x) + cosA * (pos.y - 3 - pos.y) + pos.y) };
            
            lines[8] = { int(cosA * (pos.x - 0 - pos.x) - sinA * (pos.y - 8 - pos.y) + pos.x),
                int(sinA * (pos.x - 0 - pos.x) + cosA * (pos.y - 8 - pos.y) + pos.y) };
            
            lines[9] = { int(cosA * (pos.x - pos.x) - sinA * (pos.y - 10 - pos.y) + pos.x),
                int(sinA * (pos.x - pos.x) + cosA * (pos.y - 10 - pos.y) + pos.y) };
            
            break;
    } // switch
    
    // Render and draw 
    SDL_SetRenderDrawColor(rend, 255,255,255, 255);
    SDL_RenderDrawLines(rend, lines, 10);
    SDL_RenderDrawRect(rend, &collision_rect);
}

