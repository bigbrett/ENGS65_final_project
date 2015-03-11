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

#include "GameObject.h"
#include "Bullet.h"

class Ship: public GameObject
{
private:
	static SDL_Surface *image;	// The image used for the class
	int shield;					// Damage reduction from collisions

public:
	Ship();
	virtual ~Ship();

	// Overloaded functions
    void move();
	void takeDmg(int dmg, Asteroid_GameObject_Type type);
    list<GameObject*> destroy();

	// Shoot function
	// Returns a new Bullet object located at the front of the ship,
    // traveling in the direction the ship is pointing
	Bullet shoot();
    
    // Rotate 'increment' left (negative) or right (positive)
    void rotate(int increment);
    
    // Accelerate
    void accelerate();

};

#endif /* SHIP_H_ */


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