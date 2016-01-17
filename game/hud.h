/**
* - Copyright 2015 Your Name <you@yourhost.com>
*     - Initial commit
*/

#ifndef HUD_H
#define HUD_H

#include <rt2d/entity.h>
#include "basicentity.h"

using namespace std;

class Hud: public Entity {
	public:
		Hud();
		virtual ~Hud();
		virtual void update(float deltaTime);
	
	private:
		BasicEntity* topBanner;
		BasicEntity* bottomBanner;

};

#endif /* HUD_H */ 
