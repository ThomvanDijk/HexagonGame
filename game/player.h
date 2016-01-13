/**
* - Copyright 2015 Your Name <you@yourhost.com>
*     - Initial commit
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>

class Player: public Entity {
	public:
		Player();
		virtual ~Player();
		virtual void update(float deltaTime);
		virtual void setStarted(bool s) { started = s; }
		virtual void setActive(bool a) { active = a; }
	
	private:
		int red;
		int green;
		int blue;
		bool started;
		bool active;
};

#endif /* PLAYER_H */ 
