//
//  TextRenderer.cpp
//  Asteroids
//
//  Created by Dan Berman
//  Copyright (c) 2015 Dan Berman. All rights reserved.
//

#include "TextRenderer.h"
#include <iostream>

void TextRenderer::initText()
{ 
    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
}

void TextRenderer::quitText()
{
    TTF_Quit();
}

void TextRenderer::printLives(SDL_Renderer *rend, int lives)
{
    stringstream ss;
    ss.str("");
    ss << "Lives remaining: " << lives;
    
    cout << ss.str() << endl;
    
    TTF_Font *livesFont = TTF_OpenFont("src/data-latin.ttf", 16);
    SDL_Color white = {255, 255, 255};
    SDL_Surface *surf = TTF_RenderText_Solid(livesFont, ss.str().c_str(), white);
    SDL_Texture *msg = SDL_CreateTextureFromSurface(rend, surf);
    SDL_Rect msg_rect; //create a rect
    msg_rect.x = 0;  //controls the rect's x coordinate
    msg_rect.y = 0; // controls the rect's y coordinte
    msg_rect.w = surf->w; // controls the width of the rect
    msg_rect.h = surf->h; // controls the height of the rect

    SDL_RenderCopy(rend, msg, NULL, &msg_rect);
    SDL_FreeSurface(surf);
    
}

void TextRenderer::printGameOver(SDL_Renderer *rend)
{
    stringstream ss;
    ss.str("GAME OVER");
    
    TTF_Font *gameFont = TTF_OpenFont("data-latin.ttf", 72);
    SDL_Color white = {255, 255, 255};
    SDL_Surface *surf = TTF_RenderText_Solid(gameFont, ss.str().c_str(), white);
    SDL_Texture *msg = SDL_CreateTextureFromSurface(rend, surf);
    SDL_Rect msg_rect; //create a rect
    msg_rect.x = 0;  //controls the rect's x coordinate
    msg_rect.y = 0; // controls the rect's y coordinte
    msg_rect.w = surf->w; // controls the width of the rect
    msg_rect.h = surf->h; // controls the height of the rect
    
    SDL_RenderCopy(rend, msg, NULL, &msg_rect);
    SDL_FreeSurface(surf);
}