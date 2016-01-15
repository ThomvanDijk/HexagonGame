/**
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - Initial commit
 */

#include "player.h"

Player::Player() : Entity() {
	//Here the colors are randomly set to a range from 30 to 255.
	playerColor = RGBAColor(rand() % 226 + 30, rand() % 226 + 30, rand() % 226 + 30);

	started = false;
	active = false;
}

Player::~Player() {
	
}

void Player::update(float deltaTime) {
	
}
