/**
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - Initial commit
 */

#include "building.h"

Building::Building(Player* player) : Entity() {
	this->player = player;
	time = 0;

	woodCost = 0;
	foodCost = 0;
	goldCost = 0;
	stoneCost = 0;

	woodYield = 0;
	foodYield = 0;
	goldYield = 0;
	stoneYield = 0;
}

Building::~Building() {
	
}

void Building::update(float deltaTime) {
	
}
