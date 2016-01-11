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
#include "planet.h"

GameScene::GameScene() : SuperScene() {
	origin = new Point2(SWIDTH / 2, SHEIGHT / 2);
	planet = new Planet(this, *origin);
	addChild(planet);
}

GameScene::~GameScene() {
	removeChild(planet);
	delete planet;
}

void GameScene::update(float deltaTime) {
	SuperScene::moveCamera(deltaTime);
}