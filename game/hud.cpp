/**
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - Initial commit
 */

#include "hud.h"
#include "circlebutton.h"
//#include "player.h"

using namespace std;

Hud::Hud(Scene* parent, Player* player) : Entity() {
	this->player = player;
	this->parent = parent;
	numberOfBuildings = 14;
	
	text = new Text();
	addChild(text);

	//Add the top part.
	topBanner = new BasicEntity();
	topBanner->addSprite(AUTOGENWHITE, 0.5, 0);
	topBanner->sprite()->size = Point2(SWIDTH / 1.5, SHEIGHT / 20);
	topBanner->position = Point2(SWIDTH / 2, 0);
	//topBanner->sprite()->color = RED;
	addChild(topBanner);

	//Add the bottom part.
	bottomBanner = new BasicEntity();
	bottomBanner->addSprite(AUTOGENWHITE, 0.5, 1);
	bottomBanner->sprite()->size = Point2(SWIDTH / 1.5, SHEIGHT / 6);
	bottomBanner->position = Point2(SWIDTH / 2, SHEIGHT);
	bottomBanner->sprite()->color = RED;
	addChild(bottomBanner);

	//add building buttons
	for (int i = 0; i < numberOfBuildings; i++) {
		Point size = Point(50, 50);
		Point pos = Point(SWIDTH / 2 - ((SWIDTH / 1.5) / 2) + (60 * i) + size.x, SHEIGHT - SHEIGHT / 6 + size.y - 10);

		circleButton = new CircleButton(size, pos, parent, i, player);
		addChild(circleButton);
	}
}

Hud::~Hud() {
	removeChild(topBanner);
	removeChild(bottomBanner);
	delete topBanner;
	delete bottomBanner;
}

void Hud::update(float deltaTime) {
	
	string coordinates = "x";
	coordinates.append(std::to_string(parent->camera()->position.x));
	coordinates.append(" , y");
	coordinates.append(std::to_string(parent->camera()->position.x));

	text->message(coordinates);
}
