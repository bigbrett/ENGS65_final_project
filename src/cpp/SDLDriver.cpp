//
//  SDLDriver.cpp
//
//  A wrapper class that encapsulates an SDL Graphics Application
//

#include "SDLDriver.h"

using namespace std;

SDLDriver::SDLDriver()
{
    // should this be SDL_INIT_VIDEO ?
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
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