/**
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - Initial commit
 */

#include "player.h"

Player::Player() : Entity() {
	selectedFrame = 0;

	wood = 0;
	food = 0;
	gold = 0;
	stone = 0;
}

Player::~Player() {

}

void Player::update(float deltaTime) {
	
}
