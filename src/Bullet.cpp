/*
 * Bullet.cpp
 *
 *	Code to implement the Bullet class
 *
 */

#include "Bullet.h"

Bullet::Bullet()
: GameObject(AGT_BULLET, OBJ_DEFAULT_LOCATION, OBJ_DEFAULT_SIZE,
                 OBJ_DEFAULT_ROTATION, BULLET_DEFAULT_SPEED,
                 BULLET_DEFAULT_SPEED, OBJ_DEFAULT_HEALTH,
                 BULLET_DEFAULT_DAMAGE) {};

Bullet::Bullet(Point startLoc, int xDirectionSpeed, int yDirectionSpeed,
               int _health, int _damage)
: GameObject(AGT_BULLET, startLoc, OBJ_DEFAULT_SIZE, OBJ_DEFAULT_ROTATION,
             xDirectionSpeed, yDirectionSpeed, _health, _damage) {};