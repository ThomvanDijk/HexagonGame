/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#include "hexagon.h"
#include "sprite.h"
#include <rt2d/config.h>
#include "superscene.h"
#include <iostream>
#include "player.h"
#include <vector>

RGBAColor colors[10] = { WHITE, GRAY, RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PINK, MAGENTA };

Hexagon::Hexagon(Scene* parent, int xCoord, int yCoord, float xPos, float yPos, int hexRadius, int owner, vector<Player*> playerList) : Sprite() {
	this->parent = parent;
	this->xCoord = xCoord;
	this->yCoord = yCoord;
	this->owner = owner;
	this->playerList = playerList;

	mouseDistance = 0;

	int s = playerList.size();
	for (int i = 0; i < s; i++) {
		colorList.push_back(playerList[i]->getColor());
	}

	hexColor = RGBAColor(255, 255, 255);

	setupCircleSprite(AUTOGENWHITE, hexRadius, 6);
	spriteposition = Point2(xPos, yPos);
	
	//Here I create text to show the coords of the hexes.
	/*string coordinates = "x";
	coordinates.append(std::to_string(xCoord));
	coordinates.append(" , y");
	coordinates.append(std::to_string(yCoord));

	Text* line = new Text();
	line->message(coordinates);
	line->position = Point2(xPos - hexRadius / 2, yPos);
	line->scale = Point2(0.2f, 0.2f);
	text.push_back(line);
	parent->addChild(line);*/
}

Hexagon::~Hexagon() {

}

void Hexagon::update(float deltaTime) {
	this->color = hexColor;
}

