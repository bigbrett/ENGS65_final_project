//
//  Window.h
//  Asteroids
//
//  SDL Window class for asteroids game
//  Based on code written by 
//

#ifndef __Asteroids__Window__
#define __Asteroids__Window__

#include <SDL2/SDL.h>
#include "Globals.h"
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
