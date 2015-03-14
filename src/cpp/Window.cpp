//
//  Window.cpp
//  Asteroids
//
//

#include "Window.h"

/*
 * Constructor to create an SDL window and handle errors
 */
Window::Window()
{
    gWindow = SDL_CreateWindow("ASTEROIDS!!!",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               GAME_WIDTH,
                               GAME_HEIGHT,
                               SDL_WINDOW_SHOWN);
    if (gWindow == nullptr){
        cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        SDL_Quit();
    }
}

/*
 * Default destructor to destroy and free the SDL graphics window
 */
Window::~Window()
{
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
}