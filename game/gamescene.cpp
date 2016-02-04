/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 *
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#include <iostream>

#include "gamescene.h"
#include "superScene.h"
#include "player.h"

using namespace std;

GameScene::GameScene(Player* player) : SuperScene() {
	this->player = player;

	//Add the buildings first, in order of the spritesheet.
	//farm = new Farm();
	//buildingList.push_back(farm);
	//townCenter = new TownCenter();
	//buildingList.push_back(townCenter);

	origin = new Point2(SWIDTH / 2, SHEIGHT / 2);
	grid = new Grid(this, origin, 40, 100, 62, 0, player);
	addChild(grid);

	hud = new Hud(this, player);
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
	Point cam_pos = Point(camera()->position.x, camera()->position.y);
	hud->position = Point(cam_pos.x - SWIDTH / 2, cam_pos.y - SHEIGHT / 2);

	SuperScene::update(deltaTime);
	moveCamera(deltaTime);

	player->update(deltaTime);

	//Give boolean hoverHud direcly though to setHoverHud in grid.
	grid->setHoverHud(hud->getHoverHud());

	//Give the selected menu to hud from grid.
	hud->setSelectedMenu(grid->getSelectedMenu());

	//text follows camera
	/*Point2 cam_pos = Point2(camera()->position.x, camera()->position.y);

	unsigned int s = text.size();
	for (unsigned int i = 0; i < s; i++) {
		text[i]->position = Point2(cam_pos.x + 50 - SWIDTH / 2, cam_pos.y + 50 + (30 * i) - SHEIGHT / 2);
	}*/

	if (input()->getKeyUp(GLFW_KEY_ESCAPE)) {
		this->stop();
	}
}

void GameScene::moveCamera(float deltaTime) {
	//Move Camera (Arrow up, down, left, right)
	float speed = 800.0f; // 800 units / second

	//Right and Down vector
	Point2 right = Point2(1, 0);
	Point2 up = Point2(0, 1);
	//Direction
	Vector2 direction = Vector2(0, 0);

	if (input()->getKey(GLFW_KEY_UP)) {
		direction -= up;
	}
	if (input()->getKey(GLFW_KEY_DOWN)) {
		direction += up;
	}
	if (input()->getKey(GLFW_KEY_RIGHT)) {
		direction += right;
	}
	if (input()->getKey(GLFW_KEY_LEFT)) {
		direction -= right;
	}
	direction.normalize();
	direction *= deltaTime * speed;
	camera()->position += direction;
}
