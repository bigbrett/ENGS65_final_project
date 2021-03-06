/*
 * Ship.cpp
 *
 * Code to implement Ship class
 *
 */

#include "Ship.h"

Ship::Ship(int startingLives)
    : GameObject(AGT_SHIP, SDL_Point (),
                 SHIP_DEFAULT_SIZE, SHIP_DEFAULT_SIZE, SHIP_DEFAULT_ROTATION,
                 0, 0, SHIP_DEFAULT_HEALTH, 0)
{
    collision_rect.x = SHIP_DEFAULT_X_LOCATION;
    collision_rect.y = SHIP_DEFAULT_Y_LOCATION;
    
    // Class Specific Variables
    lives = startingLives;
    shield = 0;
    accelerate = false;
    gun = new ShipGun();
}

Ship::Ship(const Ship& other) : GameObject(other)
{
    shield = other.shield;
}

void Ship::takeDmg(int dmg, Asteroid_GameObject_Type type)
{
    if (type == AGT_ASTEROID) {
        dmg -= shield;
    }
    else dmg = 0;   // Don't take damage from bullets or anything else
    
    if (dmg < 0) dmg = 0;   // Don't accidentally add health
    
    health -= dmg;
}

bool Ship::isDestroyed()
{
    if (health<=0) {
        lives--;
        collision_rect.x = SHIP_DEFAULT_X_LOCATION;
        collision_rect.y = SHIP_DEFAULT_Y_LOCATION;
        x_velocity = 0;
        y_velocity = 0;
        rotation = SHIP_DEFAULT_ROTATION * ANGLE_INC;
        health = SHIP_DEFAULT_HEALTH;
    }
    return false;
}

list<Bullet*> * Ship::shoot()
{
    SDL_Point loc;
    loc.x = collision_rect.x + collision_rect.w / 2;
    loc.y = collision_rect.y + collision_rect.h / 2;
    loc.x = int(cos(rotation) * collision_rect.w + loc.x);
    loc.y = int(-sin(rotation) * collision_rect.h + loc.y);
    
    return gun->shoot(loc, rotation);
}

void Ship::draw(SDL_Renderer* rend)
{
    float cosA = cos(rotation);
    float sinA = sin(rotation);
   
    SDL_Point* ship = new SDL_Point[5];
    SDL_Rect pos = collision_rect;
    pos.x = pos.x + pos.w / 2;  // Move coordinates to center of the rectangle
    pos.y = pos.y + pos.h / 2;
    ship[0] = {int(cosA * pos.w / 2 + pos.x), int(-sinA * pos.h / 2 + pos.y)};
    
    ship[1] = {int(-cosA * pos.w / 2 + sinA * pos.h / 2 + pos.x),
            int(sinA * pos.h / 2 + cosA * pos.w / 2 + pos.y)};
    
    ship[2] = {int(-cosA * pos.w / 4 + pos.x), int(sinA * pos.h / 4 + pos.y)};
    
    ship[3] = {int(-cosA * pos.w / 2 - sinA * pos.h / 2 + pos.x),
        int(sinA * pos.h / 2 - cosA * pos.w / 2 + pos.y)};
    
    ship[4] = {int(cosA * pos.w / 2 + pos.x), int(-sinA * pos.h / 2 + pos.y)};
    
    
    SDL_SetRenderDrawColor(rend, 255,255,255, 255);
    SDL_RenderDrawLines(rend, ship, 5);
}

void Ship::rotateCW()
{
    if(rotation <= 0) rotation = AD_ESE * ANGLE_INC;
    else rotation -= ANGLE_INC;
}

void Ship::rotateCCW()
{
    if(rotation >= AD_ESE * ANGLE_INC) rotation = 0;
    else rotation += ANGLE_INC;
}

void Ship::setAccelerate(bool accel)
{
    accelerate = accel;
    if(accelerate)
    {
        x_velocity = cos(rotation) * SHIP_DEFAULT_SPEED;
        y_velocity = -sin(rotation) * SHIP_DEFAULT_SPEED;
        
    }
    else
    {
        x_velocity = 0;
        y_velocity = 0;
    }
}
