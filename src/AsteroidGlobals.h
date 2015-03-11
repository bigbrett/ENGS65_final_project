/*
 * AsteroidGlobals.h
 *
 * Header file for global values to be used in the Asteroids game
 *
 */

#define WINDOW_HEIGHT 100
#define WINDOW_WIDTH 100

#define SHIP_startXLoc WINDOW_WIDTH/2
#define SHIP_startYLoc WINDOW_HEIGHT/2
#define SHIP_acceleration 2

enum Asteroid_GameObject_Type {AGT_GAMEOBJECT, AGT_SHIP, AGT_BULLET,
    AGT_ASTEROID};

enum Asteroid_Direction {AD_N, AD_NE, AD_E, AD_SE, AD_S, AD_SW, AD_W, AD_NW,
    AD_SIZE};
