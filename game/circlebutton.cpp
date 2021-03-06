/**
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - Initial commit
 */

#include "circlebutton.h"
#include "sprite.h"

using namespace std;

CircleButton::CircleButton(Point size, Point pos, Scene* parent, int frame, Player* player) : Entity() {
	this->player = player;
	this->parent = parent;
	this->frame = frame;
	this->pos = pos;
	this->size = size;

	color = WHITE;

	circleButton = new BasicEntity();
	circleButton->addSprite("assets/sprite_sheet.tga", 0.5, 0.5);
	circleButton->sprite()->uvdim = Point(0.125, 0.125);
	circleButton->sprite()->frame(frame);
	circleButton->sprite()->size = size;
	circleButton->position = pos;
	addChild(circleButton);
}

CircleButton::~CircleButton() {
	removeChild(circleButton);
	delete circleButton;
}

void CircleButton::update(float deltaTime) {
	circleButton->sprite()->color = color;
	circleButton->position = pos;

	float subX = (circleButton->position.x - parent->input()->getMouseX());
	float subY = (circleButton->position.y - parent->input()->getMouseY());

	float distance = sqrt((subX * subX) + (subY * subY));

	if (distance < circleButton->sprite()->size.x / 2) {
		circleButton->sprite()->color = GRAY;
		if (parent->input()->getMouseDown(0)) {
			player->setSelectedFrame(frame);
		}
	}
}
