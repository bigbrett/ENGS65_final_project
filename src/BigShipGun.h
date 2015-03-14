//
//  BigShipGun.h
//  Asteroids
//
//  Created by Dan Berman
//  Copyright (c) 2015 Dan Berman. All rights reserved.
//

#ifndef __Asteroids__BigShipGun__
#define __Asteroids__BigShipGun__

#include "ShipGun.h"

class BigShipGun : public ShipGun
{
public:
    BigShipGun(){}
    virtual ~BigShipGun(){}
    
    list<Bullet*> * shoot(SDL_Point point, float trajectory);
};
#endif /* defined(__Asteroids__BigShipGun__) */
