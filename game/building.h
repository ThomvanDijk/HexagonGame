/**
* - Copyright 2015 Your Name <you@yourhost.com>
*     - Initial commit
*/

#ifndef BUILDING_H
#define BUILDING_H

#include <rt2d/entity.h>

#include "player.h"

using namespace std;

class Building: public Entity {
	public:
		Building(Player* player);
		virtual ~Building();
		virtual void update(float deltaTime);

		virtual int getWoodCost() { return woodCost; };
		virtual int getFoodCost() { return foodCost; };
		virtual int getGoldCost() { return goldCost; };
		virtual int getStoneCost() { return stoneCost; };

		virtual int getWoodYield() { return woodYield; };
		virtual int getFoodYield() { return foodYield; };
		virtual int getGoldYield() { return goldYield; };
		virtual int getStoneYield() { return stoneYield; };

	//The classes who extend building can use these variables because of protected.
	protected:
		Player* player;
		float time;

		int woodCost;
		int foodCost;
		int goldCost;
		int stoneCost;

		int woodYield;
		int foodYield;
		int goldYield;
		int stoneYield;

};

#endif /* BUILDING_H */ 
