//
//  SDLDriver.cpp
//
//  A wrapper class that encapsulates an SDL Graphics Application
//  Based on code written by 
//

#include "SDLDriver.h"

SDLDriver::SDLDriver()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        
    }
}
SDLDriver::~SDLDriver()
{
    SDL_Quit();
}

bool SDLDriver::isRunning()
{
    return running;
}
void SDLDriver::exit()
{
    running = false;
}