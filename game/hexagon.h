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
#include <rt2d/scene.h>
#include <rt2d/timer.h>
#include <rt2d/text.h>
#include "sprite.h"

class Hexagon: public Sprite {
	public:
		Hexagon(Scene* parent, int xCoord, int yCoord, float xPos, float yPos, int hexRadius, int owner);
		virtual ~Hexagon();
		virtual float getMouseDistance() { return mouseDistance; };
		virtual void setMouseDistance(float distance) { mouseDistance = distance; };
		virtual void update(float deltaTime);
		virtual int getOwner() { return owner; };
		virtual void Hexagon::setOwner(int owner) { this->owner = owner; }
		virtual int getxCoord() { return xCoord; };
		virtual int getyCoord() { return yCoord; };
		virtual void setRGB(int red, int green, int blue);

	private:
		std::vector<Text*> text;
		Scene* parent;
		Timer timer;
		Sprite* hexagon;
		int owner; //0 = nobody, 1 = player1, 2 = player2, etc..
		int xCoord;
		int yCoord;
		float mouseDistance;
		int red;
		int green;
		int blue;
};

#endif /* HEXAGON */ 
