/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#include "mainmenu.h"
#include "button.h"
#include "superscene.h"
#include <rt2d/scene.h>
#include <iostream>

MainMenu::MainMenu() : SuperScene() {
	startButton = new Button(Point2(256, 64), Point2(SWIDTH / 2, SHEIGHT / 2 - 100), this, std::bind(&MainMenu::startGame, this));
	optionsButton = new Button(Point2(256, 64), Point2(SWIDTH / 2, SHEIGHT / 2), this, std::bind(&MainMenu::startGame, this));
	quitButton = new Button(Point2(256, 64), Point2(SWIDTH / 2, SHEIGHT / 2 + 100), this, std::bind(&MainMenu::startGame, this));

	addChild(startButton);
	addChild(optionsButton);
	addChild(quitButton);

	//Title text.
	text[0]->message("Hexes and Colors");
	text[0]->position = Point2(SWIDTH / 2 - 240, SHEIGHT / 2 - 250);
	text[0]->scale = Point2(1, 1);
}

MainMenu::~MainMenu() {
	removeChild(startButton);
	removeChild(optionsButton);
	removeChild(quitButton);

	delete startButton;
	delete optionsButton;
	delete quitButton;
}

void MainMenu::update(float deltaTime) {
	
}

void MainMenu::startGame() {
	SuperScene::activescene = 1;
	playerList[0]->setActive(true);
}
