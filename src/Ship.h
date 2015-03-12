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

#define SHIP_DEFAULT_LOCATION   0
#define SHIP_DEFAULT_SIZE       5
#define SHIP_DEFAULT_HEALTH     5

#define DOT_VEL 10      // FOR INTIAL SHIP EVENT HANDLING TESTING PURPOSES

class Ship: public GameObject
{
private:
	int shield;					// Damage reduction from collisions

public:
	Ship();
	virtual ~Ship();

	/* Overloaded Functions */
    void move();
	void takeDmg(int dmg, Asteroid_GameObject_Type type);
    list<GameObject*> destroy();
    
    /* Ship Specific Functions */

	// Shoot function
	// Returns a new Bullet object located at the front of the ship,
    // traveling in the direction the ship is pointing
	Bullet shoot();
    
    // Handle a keyboard arrow press event
    void handleKeyArrowPressEvent(SDLKey sym);
};



/*
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