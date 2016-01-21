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

Hexagon::Hexagon(Scene* parent, int xCoord, int yCoord, float xPos, float yPos, Player* player) : Sprite() {
	this->parent = parent;
	this->xCoord = xCoord;
	this->yCoord = yCoord;
	this->player = player;

	mouseDistance = 0;

	setupSprite("assets/sprite_sheet.tga", 0.5, 0.78125, 0.125, 0.125, 0, 0);
	spriteposition = Point(xPos, yPos);
	spritescale = Point(3.5, 3.5);

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
	
}
