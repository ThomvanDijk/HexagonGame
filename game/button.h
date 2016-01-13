/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <functional>
#include <rt2d/timer.h>
#include <rt2d/scene.h>
#include "basicentity.h"

class Button: public Entity {
	public:
		Button(Point2 size, Point2 pos, Scene* parent, std::function<void()> action);
		virtual ~Button();
		virtual void update(float deltaTime);
	
	private:
		std::function<void()> action;
		Timer timer;
		BasicEntity* button;
		Scene* parent;
		Point2 pos;
		Point2 size;
};

#endif /* BUTTON_H */ 
