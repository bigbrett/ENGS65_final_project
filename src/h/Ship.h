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
#include <iostream>

#include "GameObject.h"
#include "Bullet.h"

using namespace std;

class Ship: public GameObject
{
private:
	int shield;					// Damage reduction from collisions

public:
	Ship();
    Ship(const Ship& other);
    virtual ~Ship() {} // Nothing to destroy

	/* Overloaded Functions */
	void takeDmg(int dmg, Asteroid_GameObject_Type type);
    list<GameObject*> * destroy();
    
    /* Ship Specific Functions */

	// Shoot function
	// Returns a new Bullet object located at the front of the ship,
    // traveling in the direction the ship is pointing
	Bullet * shoot();
    
    // Handle a keyboard arrow press event
    void handleKeyboardEvent(SDL_Event &e);
    void draw(SDL_Renderer* rend);
};



/*
<<<<<<< HEAD
=======

>>>>>>> ebd48a8760013fe5207eaa2f90a0f45408f6a5c8
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
*/

#endif /* SHIP_H_ */
