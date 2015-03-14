//
//  TextRenderer.h
//  Asteroids
//
//  Created by Dan Berman
//  Copyright (c) 2015 Dan Berman. All rights reserved.
//

#ifndef __Asteroids__Text__
#define __Asteroids__Text__

#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "Globals.h"

using namespace std;

class TextRenderer {
public:
    static void initText();
    static void quitText();
    static void printGameData(SDL_Renderer *rend, int lives, int score);
    static void printGameOverLose(SDL_Renderer *rend);
    static void printGameOverWin(SDL_Renderer *rend);
};

#endif /* defined(__Asteroids__Text__) */
