/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#ifndef PLANET_H
#define PLANET_H

#include <vector>
#include <rt2d/timer.h>
#include "basicentity.h"
#include "grid.h"

class Planet: public Entity {
	public:
		Planet(Scene* parent, Point2 origin);
		virtual ~Planet();
		virtual void update(float deltaTime);
	
	private:
		Scene* parent;
		Point2 origin;
		Grid* grid;
		Timer timer;
};

#endif /* PLANET_H */ 
