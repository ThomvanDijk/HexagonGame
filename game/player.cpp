/**
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - Initial commit
 */

#include "player.h"

Player::Player() : Entity() {
	selectedFrame = 0;

	wood = 1000;
	food = 1000;
	gold = 1000;
	stone = 1000;
}

Player::~Player() {

}

void Player::update(float deltaTime) {
	
}
