/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 *
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#include <iostream>
#include <vector>

#include "grid.h"
#include "basicentity.h"
#include "hexagon.h"
#include "player.h"

using namespace std;

Grid::Grid(Scene* parent, Point2* origin, int size, int hexWidth, int hexHeight, float padding, Player* player, vector<Building*> buildingList) : Entity() {
	this->buildingList = buildingList;
	this->parent = parent;
	this->origin = origin;
	this->player = player;
	this->hexWidth = hexWidth;

	lastHovered = 0;
	hoverHud = false;
	loaded = false;

	double xOff = cos(30 * DEG_TO_RAD) * (hexWidth + padding);
	double yOff = sin(30 * DEG_TO_RAD) * (hexHeight + padding);
	int half = size / 2;

	//create the grid
	for (int row = 0; row < size; row++) {
		int cols = size - abs(row - half);

		for (int col = 0; col < cols; col++) {
			//simple coordinates
			int xCoord = row < half ? col - row : col - half;
			int yCoord = row - half;

			//precise position
			float xPos = (int)(origin->x + xOff * (col * 2 + 1 - cols));
			float yPos = (int)(origin->y + yOff * (row - half) * 3);

			//create hexagon
			hexagon = new Hexagon(parent, xCoord, yCoord, xPos, yPos, player);

			//set frame
			int f = 62; //rand() % 3;
			hexagon->frame(f);

			//to the Entity vector<Sprite*> _spritebatch
			_spritebatch.push_back(hexagon);
		}
	}
}

Grid::~Grid() {
	//int s = _spritebatch.size();
	//for (int i = 0; i < s; i++) {

	//}
}

void Grid::update(float deltaTime) {
	int batchSize = _spritebatch.size();
	//Due to a bug in rt2d I need to have a variable loaded.
	if (loaded) { loaded = true; }

	for (int i = 0; i < batchSize; i++) {
		Hexagon* thisHex = (Hexagon*)_spritebatch[i];
		Hexagon* lastHex = (Hexagon*)_spritebatch[lastHovered];

		thisHex->color = WHITE;
		thisHex->update(deltaTime);

		float mousex = parent->input()->getMouseX() + parent->camera()->position.x - SWIDTH / 2;
		float mousey = parent->input()->getMouseY() + parent->camera()->position.y - SHEIGHT / 2;

		float subX = (thisHex->spriteposition.x - mousex);
		float subY = (thisHex->spriteposition.y - mousey);

		float distance = sqrt((subX * subX) + (subY * subY));
		thisHex->setMouseDistance(distance);

		int selected = player->getSelectedFrame();

		//Detect mouse klick, frame 63 is nothing.
		if (parent->input()->getMouseDown(0) && loaded && player->getSelectedFrame() != 63 && !hoverHud && lastHex->frame() != selected) {
			int woodCost = buildingList[selected]->getWoodCost();
			int foodCost = buildingList[selected]->getFoodCost();
			int goldCost = buildingList[selected]->getGoldCost();
			int stoneCost = buildingList[selected]->getStoneCost();

			if (player->wood >= woodCost && player->food >= foodCost && player->gold >= goldCost && player->stone >= stoneCost) {
				player->wood -= woodCost;
				player->food -= foodCost;
				player->gold -= goldCost;
				player->stone -= stoneCost;

				cout << lastHex->frame() << endl;

				lastHex->frame(selected);
			}
			loaded = false;
		}

		//Deselect building
		if (parent->input()->getMouseDown(1) && loaded) {
			//Select last frame (nothing).
			player->setSelectedFrame(63);
			loaded = false;
		}

		//If the distance is lower than the last distance then swich to last hovered hex.
		if (distance < lastHex->getMouseDistance() && distance < 100 && !hoverHud) { //100 = radius
			lastHovered = i;
		}
		if (distance < 100 && !hoverHud) { //100 = radius
			lastHex->color = GRAY;
		}
	}

	//Apperently if you have a bool to prevent a klick before the scene is loaded, you have
	loaded = true;
}
