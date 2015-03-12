//
//  Globals.h
//  Asteroids
//
//  Created by Brett Nicholas on 3/12/15.
//  Copyright (c) 2015 Brett Nicholas. All rights reserved.
//

#ifndef Asteroids_Globals_h
#define Asteroids_Globals_h

#define GAME_WIDTH  640
#define GAME_HEIGHT 480

#define PI 3.14159

#define OBJ_DEFAULT_LOCATION    -1
#define OBJ_DEFAULT_SIZE        -1
#define OBJ_DEFAULT_ROTATION    AD_SIZE
#define OBJ_DEFAULT_SPEED       0
#define OBJ_DEFAULT_HEALTH      -1
#define OBJ_DEFAULT_DAMAGE      0

enum Asteroid_GameObject_Type
{
    AGT_GAMEOBJECT, AGT_SHIP, AGT_BULLET, AGT_ASTEROID
};

enum Asteroid_Direction
{
    AD_N, AD_NNE, AD_NE, AD_ENE, AD_E, AD_ESE, AD_SE, AD_SSE, AD_S, AD_SSW,
    AD_SW, AD_WSW, AD_W, AD_WNW, AD_NW, AD_NNW, AD_SIZE
};


#endif
