/**
* - Copyright 2015 Your Name <you@yourhost.com>
*     - Initial commit
*/

#ifndef FARM_H
#define FARM_H

#include "../building.h"

using namespace std;

class Farm : public Building {
	public:
		Farm();
		virtual ~Farm();
		virtual void update(float deltaTime);

	private:

};

#endif /* FARM_H */ 
