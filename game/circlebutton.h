/**
* - Copyright 2015 Your Name <you@yourhost.com>
*     - Initial commit
*/

#ifndef CIRCLEBUTTON_H
#define CIRCLEBUTTON_H

#include <rt2d/entity.h>
#include "basicentity.h"
#include <rt2d/scene.h>
#include "sprite.h"
#include "player.h"

using namespace std;

class CircleButton : public Entity {
	public:
		CircleButton(Point size, Point pos, Scene* parent, int frame, Player* player);
		virtual ~CircleButton();
		virtual void update(float deltaTime);
		virtual void setPos(Point p) { pos = p; }
		virtual void setColor(RGBAColor c) { color = c; }
	
	private:
		BasicEntity* circleButton;
		Scene* parent;
		Player* player;
		Point pos;
		Point size;
		int frame;
		RGBAColor color;

};

#endif /* CIRCLEBUTTON_H */ 
