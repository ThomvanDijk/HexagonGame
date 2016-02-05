/**
* - Copyright 2015 Your Name <you@yourhost.com>
*     - Initial commit
*/

#ifndef TOWNCENTER_H
#define TOWNCENTER_H

#include "../building.h"

using namespace std;

class TownCenter : public Building {
	public:
		TownCenter(Player* player);
		virtual ~TownCenter();
		virtual void update(float deltaTime);

	private:
		bool placed;

};

#endif /* TOWNCENTER_H */ 
