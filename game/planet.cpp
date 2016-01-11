/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#include "planet.h"
#include "grid.h"
#include <iostream>
#include "basicentity.h"

//RGBAColor colors[10] = { WHITE, GRAY, RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PINK, MAGENTA };

Planet::Planet(Scene* parent, Point2 origin): Entity() {
	this->parent = parent;
	this->origin = origin;

	//The padding is -0.67f because I got problems with the borders of the hexes looking black.
	grid = new Grid(parent, origin, 100, 20, -0.67f);
	addChild(grid);
}

Planet::~Planet() {
	removeChild(grid);
	delete grid;
}

void Planet::update(float deltaTime) {

}

