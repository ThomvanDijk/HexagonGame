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
		CircleButton(Point2 size, Point2 pos, Scene* parent, int frame, Player* player);
		virtual ~CircleButton();
		virtual void update(float deltaTime);
	
	private:
		BasicEntity* circleButton;
		Scene* parent;
		Player* player;
		Point2 pos;
		Point2 size;
		int frame;

};

#endif /* CIRCLEBUTTON_H */ 
