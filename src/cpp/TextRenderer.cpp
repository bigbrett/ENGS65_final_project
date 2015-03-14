//
//  TextRenderer.cpp
//  Asteroids
//
//  Created by Dan Berman
//  Copyright (c) 2015 Dan Berman. All rights reserved.
//

#include "TextRenderer.h"

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
    
    TTF_Font *livesFont = TTF_OpenFont("/Users/Dan1/Desktop/Asteroids/data-latin.ttf", 16);
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
    TTF_CloseFont(livesFont);
    SDL_DestroyTexture(msg);
    
}

void TextRenderer::printGameOverLose(SDL_Renderer *rend)
{
    stringstream ss;
    ss.str("GAME OVER! YOU LOSE!");
    
    TTF_Font *gameFont = TTF_OpenFont("/Users/Dan1/Desktop/Asteroids/data-latin.ttf", 72);
    SDL_Color white = {255, 255, 255};
    SDL_Surface *surf = TTF_RenderText_Solid(gameFont, ss.str().c_str(), white);
    SDL_Texture *msg = SDL_CreateTextureFromSurface(rend, surf);
    
    SDL_Rect msg_rect; //create a rect
    msg_rect.w = surf->w; // controls the width of the rect
    msg_rect.h = surf->h; // controls the height of the rect
    msg_rect.x = GAME_WIDTH / 2 - msg_rect.w / 2;  //controls the rect's x coordinate
    msg_rect.y = GAME_HEIGHT / 2 - msg_rect.h / 2; // controls the rect's y coordinte
    
    SDL_RenderCopy(rend, msg, NULL, &msg_rect);
    SDL_FreeSurface(surf);
    TTF_CloseFont(gameFont);
    SDL_DestroyTexture(msg);
}

void TextRenderer::printGameOverWin(SDL_Renderer *rend)
{
    stringstream ss;
    ss.str("GAME OVER! YOU WIN!");
    
    TTF_Font *gameFont = TTF_OpenFont("/Users/Dan1/Desktop/Asteroids/data-latin.ttf", 72);
    SDL_Color white = {255, 255, 255};
    SDL_Surface *surf = TTF_RenderText_Solid(gameFont, ss.str().c_str(), white);
    SDL_Texture *msg = SDL_CreateTextureFromSurface(rend, surf);
    
    SDL_Rect msg_rect; //create a rect
    msg_rect.w = surf->w; // controls the width of the rect
    msg_rect.h = surf->h; // controls the height of the rect
    msg_rect.x = GAME_WIDTH / 2 - msg_rect.w / 2;  //controls the rect's x coordinate
    msg_rect.y = GAME_HEIGHT / 2 - msg_rect.h / 2; // controls the rect's y coordinte
    
    SDL_RenderCopy(rend, msg, NULL, &msg_rect);
    SDL_FreeSurface(surf);
    TTF_CloseFont(gameFont);
    SDL_DestroyTexture(msg);
}