/**
* - Copyright 2015 Your Name <you@yourhost.com>
*     - Initial commit
*/

#ifndef RESOURCES_H
#define RESOURCES_H

#include <rt2d/entity.h>
#include <vector>

using namespace std;

class Resources: public Entity {
	public:
		Resources();
		virtual ~Resources();
		virtual void update(float deltaTime);

	private:
		int selectedBuilding;
};

#endif /* RESOURCES_H */ 
