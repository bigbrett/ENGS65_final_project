//
//  Window.h
//  Asteroids
//
//  SDL Window class for asteroids game
//

#ifndef __Asteroids__Window__
#define __Asteroids__Window__

#include <SDL2/SDL.h>
#include "Globals.h"
#include <iostream>

using namespace std;

class Window
{
private:
public:
    // pointer to the graphics window initialized to null
    SDL_Window *gWindow = NULL;
    
    Window();
    ~Window();
};

#endif /* defined(__Asteroids__Window__) */
