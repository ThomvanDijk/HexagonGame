/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#include "gamescene.h"
#include "superscene.h"
#include "player.h"
#include <iostream>

using namespace std;

GameScene::GameScene(Player* player) : SuperScene() {
	this->player = player;

	origin = new Point2(SWIDTH / 2, SHEIGHT / 2);

	grid = new Grid(this, origin, 13, 57, 44, 0, player);
	addChild(grid);

	resources = new Resources();
	addChild(resources);

	hud = new Hud(this, player, resources);
	addChild(hud);
}

GameScene::~GameScene() {
	removeChild(grid);
	removeChild(hud);
	delete grid;
	delete hud;
}

void GameScene::update(float deltaTime) {
	//Let the hud follow the camera before the camera gets updated!
	Point2 cam_pos = Point2(camera()->position.x, camera()->position.y);
	hud->position = Point2(cam_pos.x - SWIDTH / 2, cam_pos.y - SHEIGHT / 2);

	SuperScene::update(deltaTime);
	SuperScene::moveCamera(deltaTime);
}
