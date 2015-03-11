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
#include <forward_list>
//#include "AsteroidGlobals.h"
#include "GameObject.h"

using namespace std;

class Game {
	forward_list<GameObject> objects; 	// A SLL to hold all the GameObjects
	int lives;							// Number of lives the player has remaining
public:
	Game();
	virtual ~Game();
};

#endif /* GAME_H_ */
