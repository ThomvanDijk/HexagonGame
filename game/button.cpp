/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#include "button.h"
#include <iostream>

Button::Button(Point2 size, Point2 pos, Scene* parent, std::function<void()> action) : Entity() {
	this->parent = parent;
	this->action = action;
	this->pos = pos;
	this->size = size;

	button = new BasicEntity();
	button->addSprite(AUTOGENWHITE);
	button->sprite()->size = size;
	button->position = pos;
	//button->sprite()->color = RED;
	addChild(button);
}

Button::~Button() {
	removeChild(button);
	delete button;
}

void Button::update(float deltaTime) {
	float mousex = parent->input()->getMouseX() + parent->camera()->position.x - SWIDTH / 2;
	float mousey = parent->input()->getMouseY() + parent->camera()->position.y - SHEIGHT / 2;

	float buttonLeft = pos.x - (size.x / 2);
	float buttonRight = pos.x + (size.x / 2);
	float buttonTop = pos.y + (size.y / 2);
	float buttonDown = pos.y - (size.y / 2);

	//If you hover...
	if (mousex > buttonLeft && mousex < buttonRight && buttonTop > mousey && buttonDown < mousey) {
		button->sprite()->color = RED;
		if (parent->input()->getMouseDown(0)) {
			action();
		}
	}
	else {
		button->sprite()->color = WHITE;
	}
}

