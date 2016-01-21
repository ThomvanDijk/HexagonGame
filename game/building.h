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

	private:

};

#endif /* BUILDING_H */ 
