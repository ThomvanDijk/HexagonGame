/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#ifndef SUPERSCENE_H
#define SUPERSCENE_H

#include <rt2d/scene.h>
#include <rt2d/text.h>

using namespace std;

class SuperScene: public Scene {
	public:
		SuperScene();
		virtual ~SuperScene();
		virtual void update(float deltaTime);
		static int activescene;

	protected:
		unsigned int top_layer;
		Text* text;

};

#endif /* SUPERSCENE_H */ 
