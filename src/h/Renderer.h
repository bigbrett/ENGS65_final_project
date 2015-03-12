//
//  Renderer.h
//  Test
//
//  Based on code written by 
//

#ifndef __Test__Renderer__
#define __Test__Renderer__

#include <SDL2/SDL.h>

class Renderer
{
public:
    SDL_Renderer* gRenderer = NULL;
    
    Renderer();
    Renderer(SDL_Window* gWindow);
    ~Renderer();
    
    void clear();
    void present();
};

#endif /* defined(__Test__Renderer__) */
