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
		virtual void setStarted(bool s) { started = s; }
		virtual bool getStarted() { return started; }
		virtual void setActive(bool a) { active = a; }
		virtual bool getActive() { return active; }
		virtual RGBAColor getColor() { return playerColor; }
	
	private:
		RGBAColor playerColor;
		bool started;
		bool active;
};

#endif /* PLAYER_H */ 
