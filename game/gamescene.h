/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <vector>
#include "superscene.h"
#include <rt2d/text.h>
#include "basicentity.h"
#include "planet.h"

class GameScene: public SuperScene {
	public:
		GameScene();
		virtual ~GameScene();
		virtual void update(float deltaTime);

	private:
		Planet* planet;
		Point2* origin;
};

#endif /* GAMESCENE_H */ 
