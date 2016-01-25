/**
* - Copyright 2015 Your Name <you@yourhost.com>
*     - Initial commit
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>
#include <vector>

using namespace std;

class Player: public Entity {
	public:
		Player();
		virtual ~Player();
		virtual void update(float deltaTime);
		virtual void setSelectedBuilding(int s) { selectedBuilding = s; }
		virtual int getSelectedBuilding() { return selectedBuilding; }

		int wood;
		int food;
		int gold;
		int stone;

	private:
		int selectedBuilding;

};

#endif /* PLAYER_H */ 
