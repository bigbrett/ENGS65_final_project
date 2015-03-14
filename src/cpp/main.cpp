// Main.cpp
// By Dan Berman and Brett Nicholas

// Contains just the main function:
// Creates an instance of Game, which runs the full game

// Requires SDL2 and SDL2_ttf libraries in addition to standard C++ libraries
// and program code files.

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <cstdlib>
#include <ctime>
#include <list>
#include <random>
#include <chrono>

#include "Game.h"
#include "Globals.h"
#include "GameObject.h"
#include "SDLDriver.h"
#include "Renderer.h"
#include "Window.h"
#include "TextRenderer.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "ShipGun.h"
#include "BigShipGun.h"




int main( int argc, char* args[] )
{
    Game(3,5,0);
    
    return 0;
}