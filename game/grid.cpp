/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#include "grid.h"
#include <iostream>
#include "basicentity.h"
#include "hexagon.h"

using namespace std;

Grid::Grid(Scene* parent, Point2 origin, int size, int hexRadius, float padding) : Entity() {
	this->parent = parent;
	this->origin = origin;
	this->hexRadius = hexRadius;
	lastHovered = 0;

	//parent->   

	double xOff = cos(30 * DEG_TO_RAD) * (hexRadius + padding);
	double yOff = sin(30 * DEG_TO_RAD) * (hexRadius + padding);
	int half = size / 2;

	//create the grid
	for (int row = 0; row < size; row++) {
		int cols = size - abs(row - half);

		for (int col = 0; col < cols; col++) {
			//simple coordinates
			int xCoord = row < half ? col - row : col - half;
			int yCoord = row - half;

			//precise position
			float xPos = (int)(origin.x + xOff * (col * 2 + 1 - cols));
			float yPos = (int)(origin.y + yOff * (row - half) * 3);

			//create random number for the Hexagon, range 0-63
			frameNumber = rand() % 1;
			//Create hexagon.
			hexagon = new Hexagon(xCoord, yCoord, xPos, yPos, hexRadius, frameNumber);

			//to the Entity vector<Sprite*> _spritebatch
			_spritebatch.push_back(hexagon); 
		}
	}
}

Grid::~Grid() {

}

void Grid::update(float deltaTime) {
	int batchSize = _spritebatch.size();
	bool klicked = true;

	for (int i = 0; i < batchSize; i++) {
		Hexagon* thisHex = (Hexagon*)_spritebatch[i];
		Hexagon* lastHex = (Hexagon*)_spritebatch[lastHovered];
		
		thisHex->update(deltaTime);

		float mousex = parent->input()->getMouseX() + parent->camera()->position.x - SWIDTH / 2;
		float mousey = parent->input()->getMouseY() + parent->camera()->position.y - SHEIGHT / 2;

		float subX = (thisHex->spriteposition.x - mousex);
		float subY = (thisHex->spriteposition.y - mousey);

		float distance = sqrt((subX * subX) + (subY * subY));
		thisHex->setMouseDistance(distance);

		//detect mouse klick
		if (parent->input()->getMouseDown(0) && klicked) {
			lastHex->setFrame(2);
			klicked = false;
			cout << lastHex->getFrame() << endl;
		}

		//If the distance is lower than the last distance then swich to last hovered hex.
		if (distance < lastHex->getMouseDistance()) {
			lastHovered = i;
		}

		else {
			lastHex->color = GREEN;
		}
	}

	gridRules(deltaTime);
}

void Grid::gridRules(float deltaTime) {

}
