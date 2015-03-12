//
//  SDLDriver.h
//  Test
//
//  Based on code written by 
//

#ifndef __Test__SDLDriver__
#define __Test__SDLDriver__

#include <SDL2/SDL.h>

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
