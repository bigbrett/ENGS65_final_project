/*
 * Bullet.h
 *
 *	Bullet Class
 *	Inherits from GameObject class
 *
 *	Represents a bullet on the game play field
 *
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "GameObject.h"

class Bullet: public GameObject {
public:
	Bullet();
	virtual ~Bullet();
};

#endif /* BULLET_H_ */
