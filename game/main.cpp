/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#include <rt2d/core.h>
#include <vector>
#include "mainmenu.h"
#include "gamescene.h"

using namespace std;

int main(void) {
	// Core instance
	Core core;

	int numberOfPlayers = 2;

	vector<SuperScene*> scenes;
	scenes.push_back(new MainMenu());
	scenes.push_back(new GameScene());
	int s = scenes.size();

	vector<Player*> playerList;

	for (int i = 0; i < numberOfPlayers; i++) {
		Player* p = new Player(); // create a new Bullet on the heap
		playerList.push_back(p);
	}

	// add our Player to the (Super)Scenes to keep track of it
	for (int i = 0; i < s; i++) {
		scenes[i]->addPlayerList(playerList);
	}

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
