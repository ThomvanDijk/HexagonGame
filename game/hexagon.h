/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#ifndef HEXAGON
#define HEXAGON

#include <vector>
#include <rt2d/timer.h>
#include "sprite.h"

class Hexagon: public Sprite {
	public:
		Hexagon(int xCoord, int yCoord, float xPos, float yPos, int hexRadius, int frame);
		virtual ~Hexagon();
		virtual float getMouseDistance() { return mouseDistance; };
		virtual void setMouseDistance(float distance) { mouseDistance = distance; };
		virtual void update(float deltaTime);
		virtual void hexFrame(int frame);
		virtual int getFrame() { return frame; };
		virtual void setFrame(int frame);
		virtual int getxCoord() { return xCoord; };
		virtual int getyCoord() { return yCoord; };
	
	private:
		Timer timer;
		Sprite* hexagon;
		int frame;
		int xCoord;
		int yCoord;
		float mouseDistance;
		
};

#endif /* HEXAGON */ 
