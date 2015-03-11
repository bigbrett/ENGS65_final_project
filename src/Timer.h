//
//  Timer.h
//  Asteroids
//
//  Created by Brett Nicholas on 3/11/15.
//  Copyright (c) 2015 Brett Nicholas. All rights reserved.
//

#ifndef __Asteroids__Timer__
#define __Asteroids__Timer__

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>

class LTimer
{
public:
    //Initializes variables
    LTimer();
    
    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();
    
    //Gets the timer's time
    Uint32 getTicks();
    
    //Checks the status of the timer
    bool isStarted();
    bool isPaused();
    
private:
    //The clock time when the timer started
    Uint32 mStartTicks;
    
    //The ticks stored when the timer was paused
    Uint32 mPausedTicks;
    
    //The timer status
    bool mPaused;
    bool mStarted;
};


#endif /* defined(__Asteroids__Timer__) */