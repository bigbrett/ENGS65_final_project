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
    
    // Create the lives string
    ss.str("");
    ss << "Lives remaining: " << lives;
    
    // Initialize the font to use
    TTF_Font *livesFont = TTF_OpenFont(FONT_PATH, 16);
    if (!livesFont) {
        cout << "TTF_OpenFont: " << TTF_GetError() << endl;
        // handle error
        
    }
    else
    {
        SDL_Color white = {255, 255, 255};
        
        // Put the text onto a surface, render that into a texture
        SDL_Surface *surf = TTF_RenderText_Solid(livesFont, ss.str().c_str(), white);
        SDL_Texture *msg = SDL_CreateTextureFromSurface(rend, surf);
        
        // Create bounding rectangle for the text
        SDL_Rect msg_rect;
        msg_rect.x = 0;
        msg_rect.y = 0;
        msg_rect.w = surf->w;
        msg_rect.h = surf->h;
        
        // Copy the text onto the current render target
        SDL_RenderCopy(rend, msg, NULL, &msg_rect);
        
        // Free the surface and texture
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(msg);
        
        // Create the score string
        ss.str("");
        ss << "Score: " << score;
        
        // Put the text onto a surface, render that into a texture
        surf = TTF_RenderText_Solid(livesFont, ss.str().c_str(), white);
        msg = SDL_CreateTextureFromSurface(rend, surf);
        
        // Create bounding rectangle for the text
        SDL_Rect msg_rect2;
        msg_rect2.x = 0;
        msg_rect2.y = msg_rect.h + 5;   // We want to be just below lives
        msg_rect2.w = surf->w;
        msg_rect2.h = surf->h;
        
        // Copy the text onto the current render target
        SDL_RenderCopy(rend, msg, NULL, &msg_rect2);
        
        // Free the surface, texture and font
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(msg);
        TTF_CloseFont(livesFont);
    }
}

void TextRenderer::printGameOverLose(SDL_Renderer *rend)
{
    // Create the Game Over string
    stringstream ss;
    ss.str("GAME OVER! YOU LOSE!");
    
    // Initialize the font
    TTF_Font *gameFont = TTF_OpenFont(FONT_PATH, 72);
    if (!gameFont) {
        cout << "TTF_OpenFont: " << TTF_GetError() << endl;
        // handle error
        
    }
    else
    {
        SDL_Color white = {255, 255, 255};
        
        // Put the text onto a surface, render that into a texture
        SDL_Surface *surf = TTF_RenderText_Solid(gameFont, ss.str().c_str(), white);
        SDL_Texture *msg = SDL_CreateTextureFromSurface(rend, surf);
        
        // Create bounding rectangle for the text
        SDL_Rect msg_rect;
        msg_rect.w = surf->w;
        msg_rect.h = surf->h;
        msg_rect.x = GAME_WIDTH / 2 - msg_rect.w / 2;
        msg_rect.y = GAME_HEIGHT / 2 - msg_rect.h / 2;
        
        // Copy the text onto the current render target
        SDL_RenderCopy(rend, msg, NULL, &msg_rect);
        
        // Free the surface, texture and font
        SDL_FreeSurface(surf);
        TTF_CloseFont(gameFont);
        SDL_DestroyTexture(msg);
    }
}

void TextRenderer::printGameOverWin(SDL_Renderer *rend)
{
    // Create the Game Over string
    stringstream ss;
    ss.str("GAME OVER! YOU WIN!");
    
    // Initialize the font
    TTF_Font *gameFont = TTF_OpenFont(FONT_PATH, 72);
    if (!gameFont) {
        cout << "TTF_OpenFont: " << TTF_GetError() << endl;
        // handle error
        
    }
    else
    {
        SDL_Color white = {255, 255, 255};
        
        // Put the text onto a surface, render that into a texture
        SDL_Surface *surf = TTF_RenderText_Solid(gameFont, ss.str().c_str(), white);
        SDL_Texture *msg = SDL_CreateTextureFromSurface(rend, surf);
        
        // Create bounding rectangle for the text
        SDL_Rect msg_rect;
        msg_rect.w = surf->w;
        msg_rect.h = surf->h;
        msg_rect.x = GAME_WIDTH / 2 - msg_rect.w / 2;
        msg_rect.y = GAME_HEIGHT / 2 - msg_rect.h / 2;
        
        // Copy the text onto the current render target
        SDL_RenderCopy(rend, msg, NULL, &msg_rect);
        
        // Free the surface, texture and font
        SDL_FreeSurface(surf);
        TTF_CloseFont(gameFont);
        SDL_DestroyTexture(msg);
    }
}