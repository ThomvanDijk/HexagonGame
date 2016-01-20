/**
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - Initial commit
 */

#include "hud.h"
#include "circlebutton.h"
//#include "player.h"

using namespace std;

Hud::Hud(Scene* parent, Player* player, Resources* resources) : Entity() {
	this->player = player;
	this->parent = parent;
	this->resources = resources;
	numberOfBuildings = 14;
	
	//Add the top part.
	topBanner = new BasicEntity();
	topBanner->addSprite(AUTOGENWHITE, 0.5, 0);
	topBanner->sprite()->size = Point2(SWIDTH / 1.5, SHEIGHT / 20);
	topBanner->position = Point2(SWIDTH / 2, 0);
	topBanner->sprite()->color = RED;
	addChild(topBanner);

	//Add the bottom part.
	bottomBanner = new BasicEntity();
	bottomBanner->addSprite(AUTOGENWHITE, 0.5, 1);
	bottomBanner->sprite()->size = Point2(SWIDTH / 1.5, SHEIGHT / 6);
	bottomBanner->position = Point2(SWIDTH / 2, SHEIGHT);
	bottomBanner->sprite()->color = RED;
	addChild(bottomBanner);

	//Add text after the hud elements.
	woodText = new Text();
	addChild(woodText);
	woodText->scale = Point2(0.4f, 0.4f);
	woodText->position = Point2(topBanner->position.x - topBanner->sprite()->size.x / 2 + 18, topBanner->position.y + 18);

	stoneText = new Text();
	addChild(stoneText);
	stoneText->scale = Point2(0.4f, 0.4f);
	stoneText->position = Point2(topBanner->position.x - topBanner->sprite()->size.x / 2 + 148, topBanner->position.y + 18);

	goldText = new Text();
	addChild(goldText);
	goldText->scale = Point2(0.4f, 0.4f);
	goldText->position = Point2(topBanner->position.x - topBanner->sprite()->size.x / 2 + 288, topBanner->position.y + 18);

	foodText = new Text();
	addChild(foodText);
	foodText->scale = Point2(0.4f, 0.4f);
	foodText->position = Point2(topBanner->position.x - topBanner->sprite()->size.x / 2 + 418, topBanner->position.y + 18);

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
	string wood = "Wood: ";
	wood.append(std::to_string(resources->wood));
	woodText->message(wood);

	string stone = "Stone: ";
	stone.append(std::to_string(resources->stone));
	stoneText->message(stone);

	string gold = "Gold: ";
	gold.append(std::to_string(resources->gold));
	goldText->message(gold);

	string food = "Food: ";
	food.append(std::to_string(resources->food));
	foodText->message(food);
}
