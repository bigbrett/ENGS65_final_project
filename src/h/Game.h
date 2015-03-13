/*
 * Game.h
 *
 * Maintains a single game instance of Asteroids.
 *
 */

#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <cstdlib>
#include <ctime>
#include <list>
#include <random>

#include <SDL2/SDL.h>
#include "GameObject.h"
#include "Ship.h"
#include "Asteroid.h"  
#include "Bullet.h"
#include "SDLDriver.h"
#include "Renderer.h"
#include "Window.h"
#include "Globals.h"



using namespace std;

class Game
{
private:
    SDLDriver graphicsDriver; //wrapper class for SDL applet
    Window window; // wrapper class for SDL window object
    Renderer* renderer; // wrapper class for SDL graphics renderer object
    SDL_Event eventQ; // SDL event queue
    
    list<GameObject*> objectsInPlay; 	// A DLL to hold all the GameObjects
    Ship *ship;                         // So we can always directly access ship
    int lives;                          // Number of lives remaining
    int score;                          // Player current score
    
    
    
public:
    Game(int startingNumAsteroids, int startingLives, int startingScore);
    virtual ~Game();
    
    void play(void); // gameplay loop
    void handleEvents(void); // Handle SDL Events
    
    // Have the game update its state. Returns TRUE if game still running
    // (FALSE when player runs out of lives)
    bool updateState();
    
    // Have the game draw itself onto the window. Returns TRUE if successful
    bool drawGame();
};

#endif /* GAME_H_ */
