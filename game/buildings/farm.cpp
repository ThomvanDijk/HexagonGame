/**
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - Initial commit
 */

#include "farm.h"

Farm::Farm(Player* player) : Building(player) {
	woodCost = 100;
	foodCost = 0;
	goldCost = 20;
	stoneCost = 30;
}

Farm::~Farm() {
	
}

void Farm::update(float deltaTime) {
	int numberOfFields = fieldList.size();
	if (numberOfFields >= 1) {
		time += deltaTime;
		if (time >= 2) {
			foodYield = fieldList[0]->getFoodYield() * numberOfFields;
			player->food += foodYield;
			time = 0;
		}
		
		//cout << foodYield << endl;
	}
}
