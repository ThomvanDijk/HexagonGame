/**
* - Copyright 2015 Your Name <you@yourhost.com>
*     - Initial commit
*/

#ifndef TOWNCENTER_H
#define TOWNCENTER_H

#include <rt2d/entity.h>

using namespace std;

class Towncenter : public Entity {
	public:
		Towncenter();
		virtual ~Towncenter();
		virtual void update(float deltaTime);

	private:
		int selectedBuilding;

};

#endif /* TOWNCENTER_H */ 
