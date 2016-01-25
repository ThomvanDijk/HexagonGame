/**
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - Initial commit
 */

#include "building.h"

Building::Building() : Entity() {
	frame = 0;

	woodCost = 0;
	foodCost = 0;
	goldCost = 0;
	stoneCost = 0;
}

Building::~Building() {
	
}

void Building::update(float deltaTime) {
	
}
