/**
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - Initial commit
 */

#include "wheatfield.h"

WheatField::WheatField() : Terrain() {
	placed = false;

	woodCost = 20;
	foodCost = 0;
	goldCost = 120;
	stoneCost = 0;

	woodYield = 0;
	foodYield = 1;
	goldYield = 0;
	stoneYield = 0;
}

WheatField::~WheatField() {
	
}

void WheatField::update(float deltaTime) {
	
}
