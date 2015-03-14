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

void TextRenderer::printGameData(SDL_Renderer *rend, int lives, int score)
{
    stringstream ss;
    ss.str("");
    ss << "Lives remaining: " << lives;
    
    TTF_Font *livesFont = TTF_OpenFont(FONT_PATH, 16);
    if (!livesFont) {
        cout << "TTF_OpenFont: " << TTF_GetError() << endl;
        // handle error
        
    }
    else
    {
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
        SDL_DestroyTexture(msg);
        
        ss.str("");
        ss << "Score: " << score;
        
        surf = TTF_RenderText_Solid(livesFont, ss.str().c_str(), white);
        msg = SDL_CreateTextureFromSurface(rend, surf);
        SDL_Rect msg_rect2;
        msg_rect2.x = 0;
        msg_rect2.y = msg_rect.h + 5;
        msg_rect2.w = surf->w;
        msg_rect2.h = surf->h;
        
        SDL_RenderCopy(rend, msg, NULL, &msg_rect2);
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(msg);
        
        TTF_CloseFont(livesFont);
    }
}

void TextRenderer::printGameOverLose(SDL_Renderer *rend)
{
    stringstream ss;
    ss.str("GAME OVER! YOU LOSE!");
    
    TTF_Font *gameFont = TTF_OpenFont(FONT_PATH, 72);
    if (!gameFont) {
        cout << "TTF_OpenFont: " << TTF_GetError() << endl;
        // handle error
        
    }
    else
    {
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
}

void TextRenderer::printGameOverWin(SDL_Renderer *rend)
{
    stringstream ss;
    ss.str("GAME OVER! YOU WIN!");
    
    TTF_Font *gameFont = TTF_OpenFont(FONT_PATH, 72);
    if (!gameFont) {
        cout << "TTF_OpenFont: " << TTF_GetError() << endl;
        // handle error
        
    }
    else
    {
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
}