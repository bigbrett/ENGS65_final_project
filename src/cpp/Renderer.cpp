//
//  Renderer.cpp
//  Test
//
//  Based on code written by 
//

#include "Renderer.h"

/*
 * Constructor that creates a hardware renderer for a window passed as argument
 */
Renderer::Renderer(SDL_Window* gWindow)
{
    this->gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
}

/*
 * Destroys Hardware renderer
 */
Renderer::~Renderer()
{
    SDL_DestroyRenderer(this->gRenderer);
}


/*
 * Clears Hardware renderer queue
 */
void Renderer::clear()
{
    SDL_SetRenderDrawColor(this->gRenderer, 0, 0, 0, 255);
    SDL_RenderClear(this->gRenderer);
}

/*
 * Presents
 */
void Renderer::present()
{
    SDL_RenderPresent(this->gRenderer);
}