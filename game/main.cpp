/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#include <rt2d/core.h>
#include <time.h>
#include <vector>
#include "mainmenu.h"
#include "gamescene.h"

using namespace std;

int main(void) {
	// Core instance
	Core core;

	int seed = static_cast<int>(time(0));
	srand(seed);

	Player* player = new Player(); // create a new Player on the heap

	vector<SuperScene*> scenes;
	scenes.push_back(new MainMenu());
	scenes.push_back(new GameScene(player));
	int s = scenes.size();

	// start running with the first Scene
	SuperScene* scene = scenes[0];
	int scenecounter = 0;
	int running = 1;
	while (running) {
		scenecounter = scene->activescene;
		if (scenecounter > s - 1) { scenecounter = 0; scene->activescene = 0; }
		if (scenecounter < 0) { scenecounter = s - 1; scene->activescene = s - 1; }
		scene = scenes[scenecounter];
		core.run(scene); // update and render the current scene
		core.showFrameRate(5); // show framerate in output every n seconds
		if (!scene->isRunning()) { running = 0; } // check status of Scene every frame
	}

	// delete all scenes
	for (int i = 0; i < s; i++) {
		delete scenes[i];
		scenes[i] = NULL;
	}
	scenes.clear();

	return 0;
}
