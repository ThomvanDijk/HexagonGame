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

	//The classes who extend building can use these variables because of protected.
	protected:
		int frame;

		int woodCost;
		int foodCost;
		int goldCost;
		int stoneCost;

};

#endif /* TERRAIN_H */ 
