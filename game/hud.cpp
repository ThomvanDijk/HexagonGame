/**
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - Initial commit
 */

#include "hud.h"

Hud::Hud() : Entity() {
	topBanner = new BasicEntity();
	topBanner->addSprite(AUTOGENWHITE);
	topBanner->sprite()->size = Point2(SWIDTH / 2, SHEIGHT / 10);
	topBanner->position = Point2(SWIDTH / 2, 0);
	topBanner->sprite()->color = RED;
	addChild(topBanner);
}

Hud::~Hud() {
	removeChild(topBanner);
	delete topBanner;
}

void Hud::update(float deltaTime) {
	
}
