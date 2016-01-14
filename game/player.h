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

		virtual RGBAColor getRGBAColor() { return playerColor; }
		//virtual int getRed() { return red; }
		//virtual int getGreen() { return green; }
		//virtual int getBlue() { return blue; }
	
	private:
		RGBAColor playerColor;
		//int red;
		//int green;
		//int blue;
		bool started;
		bool active;
};

#endif /* PLAYER_H */ 
