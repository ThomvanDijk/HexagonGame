/**
* - Copyright 2015 Your Name <you@yourhost.com>
*     - Initial commit
*/

#ifndef BUILDING_H
#define BUILDING_H

#include <rt2d/entity.h>

using namespace std;

class Building: public Entity {
	public:
		Building();
		virtual ~Building();
		virtual void update(float deltaTime);

		virtual int getWoodCost() { return woodCost; };
		virtual int getFoodCost() { return foodCost; };
		virtual int getGoldCost() { return goldCost; };
		virtual int getStoneCost() { return stoneCost; };

	private:
		int frame;

		int woodCost;
		int foodCost;
		int goldCost;
		int stoneCost;

};

#endif /* BUILDING_H */ 
