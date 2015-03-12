/*
 * Game.h
 *
 * Game class
 *
 * Maintains a single game instance of Asteroids.
 *
 */

#ifndef GAME_H_
#define GAME_H_

#include <SDL2/SDL.h>
#include <cstdlib>
#include <list>
#include "GameObject.h"
#include "Ship.h"
#include "Asteroid.h"  
#include "Bullet.h"

#define DEFAULT_NUM_ASTEROIDS 10
#define DEFAULT_NUM_LIVES 3

using namespace std;

class Game
{
	list<GameObject*> objectsInPlay; 	// A SLL to hold all the GameObjects
    Ship *ship;                         // So we can always directly access ship
	int lives;                          // Number of lives remaining
    int score;                          // Player current score
public:
    Game();  // Default constructor
    Game(int startingNumAsteroids, int startingLives, int startingScore);
	virtual ~Game();
    
    // Have the game update its state. Returns TRUE if game still running
    // (FALSE when player runs out of lives)
    bool updateState();
    
    // Have the game draw itself onto the window. Returns TRUE if successful
    bool drawGame(SDL_Surface *gameWindow);
};

#endif /* GAME_H_ */