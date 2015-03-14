//
//  Globals.h
//  Asteroids
//
//  Created by Brett Nicholas
//  Copyright (c) 2015 Brett Nicholas. All rights reserved.
//

#ifndef Asteroids_Globals_h
#define Asteroids_Globals_h

#define GAME_WIDTH  1080
#define GAME_HEIGHT 720
#define KEYBOARD_TIMER_INTERVAL   100

#define FONT_PATH   "/Users/Dan1/git/ENGS65_final_project/src/media/data-latin.ttf"

#define PI 3.14159
#define ANGLE_INC 2*PI/AD_SIZE

#define OBJ_DEFAULT_LOCATION    -1
#define OBJ_DEFAULT_SIZE        -1
#define OBJ_DEFAULT_ROTATION    AD_SIZE
#define OBJ_DEFAULT_SPEED       0
#define OBJ_DEFAULT_HEALTH      -1
#define OBJ_DEFAULT_DAMAGE      0

#define SHIP_DEFAULT_X_LOCATION (GAME_WIDTH - SHIP_DEFAULT_SIZE) / 2
#define SHIP_DEFAULT_Y_LOCATION (GAME_HEIGHT - SHIP_DEFAULT_SIZE) / 2
#define SHIP_DEFAULT_ROTATION   AD_N
#define SHIP_DEFAULT_SIZE       20
#define SHIP_DEFAULT_HEALTH     5
#define SHIP_DEFAULT_SPEED      3

#define ASTEROID_DEFAULT_SIZE   AS_LARGE
#define ASTEROID_BASE_SIZE      25
#define ASTEROID_BASE_HEALTH    1
#define ASTEROID_BASE_DAMAGE    2
#define ASTEROID_MAX_SPEED      3  // To scale speed based on size: speed/size
// Allows for speeds 0-3 for large, 0-5 for
// medium and 0-11 for small

#define BULLET_DEFAULT_DAMAGE   1
#define BULLET_DEFAULT_SIZE     3
#define BULLET_DEFAULT_HEALTH   1
#define BULLET_DEFAULT_SPEED    10
#define BULLET_MAX_DISTANCE     400

#define DEFAULT_NUM_ASTEROIDS 3
#define DEFAULT_NUM_LIVES 3

enum Asteroid_GameObject_Type
{
    AGT_GAMEOBJECT, AGT_SHIP, AGT_BULLET, AGT_ASTEROID
};

enum Asteroid_Direction
{
    AD_E, AD_ENE, AD_NE, AD_NNE, AD_N, AD_NNW, AD_NW, AD_WNW, AD_W, AD_WSW,
    AD_SW, AD_SSW, AD_S, AD_SSE, AD_SE, AD_ESE, AD_SIZE
};


#endif
