/**
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - Initial commit
 */

#include "terrain.h"

Terrain::Terrain() : Entity() {
	frame = 0;

	woodCost = 0;
	foodCost = 0;
	goldCost = 0;
	stoneCost = 0;
}

Terrain::~Terrain() {
	
}

void Terrain::update(float deltaTime) {
	
}
