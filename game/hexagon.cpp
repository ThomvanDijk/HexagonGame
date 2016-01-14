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

RGBAColor colors[10] = { WHITE, GRAY, RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PINK, MAGENTA };

Hexagon::Hexagon(Scene* parent, int xCoord, int yCoord, float xPos, float yPos, int hexRadius, int owner) : Sprite() {
	this->parent = parent;
	this->xCoord = xCoord;
	this->yCoord = yCoord;
	this->owner = owner;

	red = 255;
	green = 255;
	blue = 255;

	mouseDistance = 0;

	setupCircleSprite(AUTOGENWHITE, hexRadius, 6);
	spriteposition = Point2(xPos, yPos);

	//Here I create text to show the coords of the hexes.
	/*std::string coordinates = "x";
	coordinates.append(std::to_string(xCoord));
	coordinates.append(" , y");
	coordinates.append(std::to_string(yCoord));

	Text* line = new Text();
	line->message(coordinates);
	line->position = Point2(xPos - hexRadius/2, yPos);
	line->scale = Point2(0.2f, 0.2f);
	text.push_back(line);
	parent->addChild(line);*/
}

Hexagon::~Hexagon() {

}

void Hexagon::update(float deltaTime) {
	this->color = RGBAColor(red, green, blue);
}

void Hexagon::setRGB(int red, int green, int blue) {
	this->red = red;
	this->green = green;
	this->blue = blue;
}

