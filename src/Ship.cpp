/*
 * Ship.cpp
 *
 * Code to implement Ship class
 *
 */

#include "Ship.h"

Ship::Ship()
{
    // Class Specific Variables
    shield = 0;
    
    // Parent Variables
    objectType = AGT_SHIP;
    collision_rect.x = SHIP_DEFAULT_LOCATION;
    collision_rect.y = SHIP_DEFAULT_LOCATION;
    collision_rect.h = SHIP_DEFAULT_SIZE;
    collision_rect.w = SHIP_DEFAULT_SIZE;
    rotation = OBJ_DEFAULT_ROTATION;
    x_velocity = OBJ_DEFAULT_SPEED;
    y_velocity = OBJ_DEFAULT_SPEED;
    health = SHIP_DEFAULT_HEALTH;
    damage = OBJ_DEFAULT_DAMAGE;
}

void Ship::move()
{
    /* TODO */
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

list<GameObject*> Ship::destroy()
{
    Ship tempShip = *this;
    list<GameObject*> tempList;
    tempList.push_front((GameObject*) &tempShip);
    return tempList;
}

Bullet Ship::shoot()
{
    int delX = collision_rect.w * cos(2/AD_SIZE*PI*rotation);
    int delY = collision_rect.h * sin(2/AD_SIZE*PI*rotation);
    SDL_Point loc;
    loc.x = collision_rect.x + delX;
    loc.y = collision_rect.y + delY;
    int x_vel = (x_velocity / x_velocity) * BULLET_DEFAULT_SPEED + x_velocity;
    int y_vel = (y_velocity / y_velocity) * BULLET_DEFAULT_SPEED + y_velocity;
    
    Bullet newBullet = Bullet(loc, x_vel , y_vel, BULLET_DEFAULT_DAMAGE);
    return newBullet;
}

void Ship::handleKeyArrowPressEvent(int sym){
    switch(sym)
    {
        case SDLK_UP: y_velocity -= DOT_VEL; break;
        case SDLK_DOWN: y_velocity += DOT_VEL; break;
        case SDLK_LEFT: x_velocity -= DOT_VEL; break;
        case SDLK_RIGHT: x_velocity += DOT_VEL; break;
    }
}

/*
Dot::Dot()
{
    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;
    
    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}

void Dot::handleEvent( SDL_Event& e )
{
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= DOT_VEL; break;
            case SDLK_DOWN: mVelY += DOT_VEL; break;
            case SDLK_LEFT: mVelX -= DOT_VEL; break;
            case SDLK_RIGHT: mVelX += DOT_VEL; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += DOT_VEL; break;
            case SDLK_DOWN: mVelY -= DOT_VEL; break;
            case SDLK_LEFT: mVelX += DOT_VEL; break;
            case SDLK_RIGHT: mVelX -= DOT_VEL; break;
        }
    }
}

void Dot::move()
{
    //Move the dot left or right
    mPosX += mVelX;
    
    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + DOT_WIDTH > SCREEN_WIDTH ) )
    {
        //Move back
        mPosX -= mVelX;
    }
    
    //Move the dot up or down
    mPosY += mVelY;
    
    //If the dot went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + DOT_HEIGHT > SCREEN_HEIGHT ) )
    {
        //Move back
        mPosY -= mVelY;
    }
}

void Dot::render()
{
    //Show the dot
    gDotTexture.render( mPosX, mPosY );
}
*/