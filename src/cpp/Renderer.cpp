//
//  Renderer.cpp
//  Test
//
//

#include "Renderer.h"

/*
 * Constructor that creates a hardware renderer for a window passed as argument
 */
Renderer::Renderer(SDL_Window* gWindow)
{
    this->gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (this->gRenderer == nullptr){
        SDL_DestroyWindow(gWindow);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
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