/**
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - Initial commit
 */

#include "hud.h"

Hud::Hud() : Entity() {
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
	//bottomBanner->sprite()->color = RED;
	addChild(bottomBanner);
}

Hud::~Hud() {
	removeChild(topBanner);
	removeChild(bottomBanner);
	delete topBanner;
	delete bottomBanner;
}

void Hud::update(float deltaTime) {
	
}
