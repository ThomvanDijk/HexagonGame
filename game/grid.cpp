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

Grid::Grid(Scene* parent, Point2* origin, int size, int hexWidth, int hexHeight, float padding, Player* player) : Entity() {
	this->parent = parent;
	this->origin = origin;
	this->player = player;
	this->hexWidth = hexWidth;

	lastHovered = 0;
	selectedMenu = 0;
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

}

void Grid::update(float deltaTime) {
	int batchSize = _spritebatch.size();
	//Due to a bug in rt2d I need to have a variable loaded.
	if (loaded) { loaded = true; }

	//Update buildings.
	int buildingListSize = buildingList.size();
	for (int l = 0; l < buildingListSize; l++) {
		buildingList[l]->update(deltaTime);
	}

	for (int i = 0; i < batchSize; i++) {
		Hexagon* thisHex = (Hexagon*)_spritebatch[i];
		Hexagon* lastHex = (Hexagon*)_spritebatch[lastHovered];

		thisHex->color = WHITE;
		thisHex->update(deltaTime);

		float mouseX = parent->input()->getMouseX() + parent->camera()->position.x - SWIDTH / 2;
		float mouseY = parent->input()->getMouseY() + parent->camera()->position.y - SHEIGHT / 2;

		float subX = (thisHex->spriteposition.x - mouseX);
		float subY = (thisHex->spriteposition.y - mouseY);

		float distance = sqrt((subX * subX) + (subY * subY));
		thisHex->setMouseDistance(distance);

		int selectedFrame = player->getSelectedFrame(); 

		//Detect mouse klick, frame 63 is nothing.
		//place building
		if (parent->input()->getMouseDown(0) && loaded && player->getSelectedFrame() != 63 && !hoverHud && lastHex->frame() != selectedFrame) {
			bool builded = false;

			if (player->getSelectedFrame() == 0) {
				farm = new Farm(player);
				buildingList.push_back(farm);

				lastHex->setNumberInList(buildingList.size());

				woodCost = farm->getWoodCost();	
				foodCost = farm->getFoodCost();
				goldCost = farm->getGoldCost();
				stoneCost = farm->getStoneCost();

				builded = true;
			}

			if (player->getSelectedFrame() == 61 && !lastHex->getSelected()) {
				wheatField = new WheatField();
				terrainList.push_back(wheatField);

				Farm* thisFarm = (Farm*)buildingList[selectedBuilding];
				thisFarm->addField(wheatField);

				lastHex->setNumberInList(terrainList.size());

				woodCost = wheatField->getWoodCost();
				foodCost = wheatField->getFoodCost();
				goldCost = wheatField->getGoldCost();
				stoneCost = wheatField->getStoneCost();

				builded = true;
			}

			if (player->wood >= woodCost && player->food >= foodCost && player->gold >= goldCost && player->stone >= stoneCost && builded) {
				player->wood -= woodCost;
				player->food -= foodCost;
				player->gold -= goldCost;
				player->stone -= stoneCost;

				lastHex->frame(selectedFrame);
			}
			builded = false;
			loaded = false;
		}

		//select buildings
		if (parent->input()->getMouseDown(0) && loaded && player->getSelectedFrame() == 63 && !hoverHud) {

			//frame 0 = building farm
			if (lastHex->frame() == 0) {
				//selection menu for farm
				selectedMenu = 1;

				//Here everything is selected exept for the tiles around the farm because there can be placed fields.
				for (int j = 0; j < batchSize; j++) {
					Hexagon* temp = (Hexagon*)_spritebatch[j];
					temp->setSelected(true);
					if (lastHex->getxCoord() == temp->getxCoord() - 1 && lastHex->getyCoord() == temp->getyCoord()) { temp->setSelected(false); }
					if (lastHex->getxCoord() == temp->getxCoord() && lastHex->getyCoord() == temp->getyCoord() - 1) { temp->setSelected(false); }
					if (lastHex->getxCoord() == temp->getxCoord() + 1 && lastHex->getyCoord() == temp->getyCoord() - 1) { temp->setSelected(false); }
					if (lastHex->getxCoord() == temp->getxCoord() + 1 && lastHex->getyCoord() == temp->getyCoord()) { temp->setSelected(false); }
					if (lastHex->getxCoord() == temp->getxCoord() && lastHex->getyCoord() == temp->getyCoord() + 1) { temp->setSelected(false); }
					if (lastHex->getxCoord() == temp->getxCoord() - 1 && lastHex->getyCoord() == temp->getyCoord() + 1) { temp->setSelected(false); }
				}
				selectedBuilding = lastHex->getNumberInList() - 1;
			}
			loaded = false;
		}

		//Deselect building
		if (parent->input()->getMouseDown(1) && loaded) {
			for (int k = 0; k < batchSize; k++) {
				Hexagon* temp2 = (Hexagon*)_spritebatch[k];
				temp2->setSelected(false);
			}
			//Select last frame (nothing).
			player->setSelectedFrame(63);
			//resets the menu
			selectedMenu = 0;
			selectedBuilding = -1;
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
