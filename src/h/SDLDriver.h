//
//  SDLDriver.h
//  Test
//
//  Based on code written by 
//

#ifndef __Asteroids__SDLDriver__
#define __Asteroids__SDLDriver__

#include <SDL2/SDL.h>
#include <iostream> 

using namespace std;

class SDLDriver
{
private:
    bool running = true;
public:
    SDLDriver();
    ~SDLDriver();
    
    bool isRunning();
    void exit();
};

#endif /* defined(__Test__SDLDriver__) */
