/*
 * Ship.h
 *
 * Ship class
 * Inherits from GameObject class
 *
 * Represents a ship (the player) on the game play field
 *
 */

#ifndef SHIP_H_
#define SHIP_H_

#include <SDL2/SDL.h> 
#include <SDL2_image/SDL_image.h> 
#include <stdio.h>
#include "Texture.h"

//The dot that will move around on the screen
class Dot
{
public:
    //The dimensions of the dot
    static const int DOT_WIDTH = 20;
    static const int DOT_HEIGHT = 20;
    
    //Maximum axis velocity of the dot
    static const int DOT_VEL = 10;
    
    //Initializes the variables
    Dot();
    
    //Takes key presses and adjusts the dot's velocity
    void handleEvent( SDL_Event& e );
    
    //Moves the dot
    void move();
    
    //Shows the dot on the screen
    void render();
    
private:
    //The X and Y offsets of the dot
    int mPosX, mPosY;
    
    //The velocity of the dot
    int mVelX, mVelY;
};


#endif /* SHIP_H_ */