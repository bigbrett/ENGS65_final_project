//
//  ShipGun.h
//  Asteroids
//
//  Created by Dan Berman
//  Copyright (c) 2015 Dan Berman. All rights reserved.
//
//  Basic class for different types of guns for the ship to have
//

#ifndef __Asteroids__ShipGun__
#define __Asteroids__ShipGun__

#include <cstdlib>
#include <list>
#include <SDL2/SDL.h>

#include "Globals.h"
#include "Bullet.h"

using namespace std;

class ShipGun
{
public:
    ShipGun(){}
    virtual ~ShipGun(){}
    
    // Shoot out bulllets from point along trajectory (angle in radians)
    virtual list<Bullet*> * shoot(SDL_Point point, float trajectory);
};

#endif /* defined(__Asteroids__ShipGun__) */
