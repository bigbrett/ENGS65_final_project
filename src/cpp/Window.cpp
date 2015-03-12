//
//  Window.cpp
//  Asteroids
//
//  Based on code written by
//

#include "Window.h"

/*
 * Constructor to create an SDL window 
 */
Window::Window()
{
    gWindow = SDL_CreateWindow("ASTEROIDS!!!",
                             SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED,
                             GAME_WIDTH,
                             GAME_HEIGHT,
                             SDL_WINDOW_SHOWN);
}

/*
 * Default destructor to destroy and free the SDL graphics window
 */
Window::~Window()
{
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
}