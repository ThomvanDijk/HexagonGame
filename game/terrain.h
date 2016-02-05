/**
* - Copyright 2015 Your Name <you@yourhost.com>
*     - Initial commit
*/

#ifndef TERRAIN_H
#define TERRAIN_H

#include <rt2d/entity.h>

using namespace std;

class Terrain : public Entity {
	public:
		Terrain();
		virtual ~Terrain();
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
		int woodCost;
		int foodCost;
		int goldCost;
		int stoneCost;

		int woodYield;
		int foodYield;
		int goldYield;
		int stoneYield;

};

#endif /* TERRAIN_H */ 
