/**
* - Copyright 2015 Your Name <you@yourhost.com>
*     - Initial commit
*/

#ifndef FARM_H
#define FARM_H

#include "../building.h"
#include "../terrain.h"

using namespace std;

class Farm : public Building {
	public:
		Farm(Player* player);
		virtual ~Farm();
		virtual void update(float deltaTime);
		virtual void addField(Terrain* t) { fieldList.push_back(t); };

	protected:
		vector<Terrain*> fieldList;

};

#endif /* FARM_H */ 
