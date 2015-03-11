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
#include <vector>
//#include "AsteroidGlobals.h"
#include "GameObject.h"

using namespace std;

class Game {
	vector<GameObject*> objectsInPlay; 	// A SLL to hold all the GameObjects
	int lives;							// Number of lives the player has remaining
    int score;                          // Player current score
public:
	Game();
	virtual ~Game();
    
    // Have the game update its state. Returns TRUE if game still running (FALSE when player runs out of lives)
    bool updateState();
    
    // Have the game draw itself onto the window. Returns TRUE on successful draw
    bool drawGame(SDL_Surface *gameWindow);
};

#endif /* GAME_H_ */