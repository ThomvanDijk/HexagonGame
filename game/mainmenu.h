/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#ifndef MAINMENU
#define MAINMENU

#include <vector>
#include <rt2d/timer.h>
#include <rt2d/scene.h>
#include "button.h"
#include "superscene.h"

class MainMenu: public SuperScene {
	public:
		MainMenu();
		virtual ~MainMenu();
		virtual void update(float deltaTime);
	
	private:
		Button* startButton;
		Button* optionsButton;
		Button* quitButton;
		Timer timer;
};

#endif /* MAINMENU */ 
