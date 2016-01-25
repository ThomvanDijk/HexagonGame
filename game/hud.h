/**
* - Copyright 2015 Your Name <you@yourhost.com>
*     - Initial commit
*/

#ifndef HUD_H
#define HUD_H

#include <rt2d/entity.h>
#include <rt2d/text.h>

#include "basicentity.h"
#include "circlebutton.h"
#include "player.h"

using namespace std;

class Hud: public Entity {
	public:
		Hud(Scene* parent, Player* player);
		virtual ~Hud();
		virtual void update(float deltaTime);
	
	private:
		BasicEntity* topBanner;
		BasicEntity* bottomBanner;
		int numberOfBuildings;
		CircleButton* circleButton;
		Scene* parent;
		Player* player;
		Text* woodText;
		Text* stoneText;
		Text* goldText;
		Text* foodText;

};

#endif /* HUD_H */ 
