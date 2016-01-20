/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#include "superscene.h"

int SuperScene::activescene = 0;

SuperScene::SuperScene() : Scene() {
	text = new Text();
	text->message("dev build");
	text->scale = Point(0.3, 0.3);
	addChild(text);
}

SuperScene::~SuperScene() {
	removeChild(text);
	delete text;
}

void SuperScene::update(float deltaTime) {
	//text follows camera
	Point2 cam_pos = Point2(camera()->position.x, camera()->position.y);
	text->position = Point2(cam_pos.x + 15 - SWIDTH / 2, cam_pos.y + 15 - SHEIGHT / 2);
}
