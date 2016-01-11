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
#include <iostream>

RGBAColor colors[10] = { WHITE, GRAY, RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PINK, MAGENTA };

Hexagon::Hexagon(int xCoord, int yCoord, float xPos, float yPos, int hexRadius, int frame) : Sprite() {
	this->xCoord = xCoord;
	this->yCoord = yCoord;
	this->frame = frame;
	mouseDistance = 0;

	setupCircleSprite(AUTOGENWHITE, hexRadius, 6);
	spriteposition = Point2(xPos, yPos);

	//1/8 = 0.125 - 0.002 because of margin issues, this sprite sheet is 8x8 so it only shows one sprite
	//uvdim = Point(0.123f, 0.123f);
	//uvoffset moves the spritesheet to the correct sprite
	//uvoffset = Point(-0.4375f, -0.4375f);
	
	//0 is no filter used for pixelart
	//filter(0);
	//wrap(0);
	
	//hexFrame(frame);
}

Hexagon::~Hexagon() {

}

void Hexagon::update(float deltaTime) {
	this->color = colors[this->frame];
}

void Hexagon::setFrame(int frame) {
	this->frame = frame;
	//hexFrame(frame);
}

void Hexagon::hexFrame(int frame) {
	this->frame = frame;

	int w = 1.0f / uvdim.x; //width = 8
	int h = 1.0f / uvdim.y; //height = 8

	//if there are more frames than sprites than frame = 0
	if (frame >= w*h) { frame = 0; }

	int ypos = frame / w;
	int xpos = frame % w;

	//- 0.4375f because by default the spritesheet is centered in the middle
	//+ 0.002f because I extracted 0.002f from the uvdim due to margin issues
	uvoffset.x = xpos * (uvdim.x + 0.002f) - 0.4375f;
	uvoffset.y = ypos * (uvdim.y + 0.002f) - 0.4375f;
}

