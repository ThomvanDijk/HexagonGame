/**
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - Initial commit
 */

#include "farm.h"

Farm::Farm() : Building() {
	frame = 2;

	woodCost = 100;
	foodCost = 0;
	goldCost = 20;
	stoneCost = 30;
}

Farm::~Farm() {
	
}

void Farm::update(float deltaTime) {
	
}
