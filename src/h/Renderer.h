//
//  Renderer.h
//  Test
//
//  Based on code written by 
//

#ifndef __Renderer__
#define __Renderer__

#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

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
