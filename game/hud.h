/**
* - Copyright 2015 Your Name <you@yourhost.com>
*     - Initial commit
*/

#ifndef HUD_H
#define HUD_H

#include <rt2d/entity.h>
#include <rt2d/stringutil.h>
#include <rt2d/text.h>

#include "basicentity.h"
#include "circlebutton.h"
#include "building.h"
#include "player.h"

class GameScene;

using namespace std;

class Hud: public Entity {
	public:
		Hud(Scene* parent, Player* player, vector<Building*> buildingList);
		virtual ~Hud();
		virtual void update(float deltaTime);
		virtual bool getHoverHud() { return hoverHud; }

	private:
		vector<Building*> buildingList;
		BasicEntity* topBanner;
		BasicEntity* bottomBanner;
		int numberOfBuildings;
		CircleButton* circleButton;
		Scene* parent;
		Player* player;
		bool hoverHud;

		Text* woodText;
		Text* stoneText;
		Text* goldText;
		Text* foodText;

};

#endif /* HUD_H */
