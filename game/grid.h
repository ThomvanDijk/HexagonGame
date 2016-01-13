/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#ifndef GRID
#define GRID

#include <rt2d/timer.h>
#include <rt2d/scene.h>
#include "basicentity.h"
#include "hexagon.h"
#include "player.h"

class Grid: public Entity {
	public:
		Grid(Scene* parent, Point2* origin, int size, int hexRadius, float padding);
		virtual ~Grid();
		virtual void update(float deltaTime);
		virtual void gridRules(float deltaTime);
	
	private:
		Timer timer;
		Scene* parent;
		Point2* origin;
		Hexagon* hexagon;
		int hexRadius;
		int owner; //0 = nobody, 1 = player1, 2 = player2, etc..
		int lastHovered;
};

#endif /* GRID */ 
