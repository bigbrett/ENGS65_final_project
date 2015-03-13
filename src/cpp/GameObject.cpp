//
//  GameObject.cpp
//  Asteroids
//
//  Created by Dan Berman
//  Copyright (c) 2015 Dan Berman. All rights reserved.
//

#include "GameObject.h"

void GameObject::movedOffScreen()
{
    // Check against having moved off left
    if(collision_rect.x + collision_rect.w < 0)
    {
        collision_rect.x = collision_rect.x + GAME_WIDTH;
    }
    
    // Check against having moved off right
    if (collision_rect.x > GAME_WIDTH)
    {
        collision_rect.x = GAME_WIDTH - collision_rect.x;
    }
    
    // Check against having moved off top
    if (collision_rect.y + collision_rect.h < 0)
    {
        collision_rect.y = collision_rect.y + GAME_HEIGHT;
    }
    
    // Check against having moved off bottom
    if (collision_rect.y > GAME_HEIGHT)
    {
        collision_rect.y = GAME_HEIGHT - collision_rect.y;
    }
}

void GameObject::move()
{
    {
        collision_rect.x += x_velocity;
        collision_rect.y += y_velocity;
        movedOffScreen();
    }
}