/**
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - Initial commit
 */

#include "hud.h"

using namespace std;

Hud::Hud(Scene* parent, Player* player, vector<Building*> buildingList) : Entity() {
	this->player = player;
	this->parent = parent;
	this->buildingList = buildingList;

	hoverHud = false;
	selectedMenu = 0;
	buttonSize = Point(120, 120);

	//Add the top part.
	topBanner = new BasicEntity();
	topBanner->addSprite(AUTOGENWHITE, 0.5, 0);
	topBanner->sprite()->size = Point(SWIDTH / 1.5, SHEIGHT / 20);
	topBanner->position = Point(SWIDTH / 2, 0);
	topBanner->sprite()->color = GRAY;
	addChild(topBanner);

	//Add the bottom part.
	bottomBanner = new BasicEntity();
	bottomBanner->addSprite(AUTOGENWHITE, 0.5, 1);
	bottomBanner->sprite()->size = Point(SWIDTH / 1.5, SHEIGHT / 6);
	bottomBanner->position = Point(SWIDTH / 2, SHEIGHT);
	bottomBanner->sprite()->color = GRAY;
	addChild(bottomBanner);

	//Add text after the hud elements.
	woodText = new Text();
	addChild(woodText);
	woodText->scale = Point(0.4f, 0.4f);
	woodText->position = Point(topBanner->position.x - topBanner->sprite()->size.x / 2 + 18, topBanner->position.y + 18);

	stoneText = new Text();
	addChild(stoneText);
	stoneText->scale = Point(0.4f, 0.4f);
	stoneText->position = Point(topBanner->position.x - topBanner->sprite()->size.x / 2 + 148, topBanner->position.y + 18);

	goldText = new Text();
	addChild(goldText);
	goldText->scale = Point(0.4f, 0.4f);
	goldText->position = Point(topBanner->position.x - topBanner->sprite()->size.x / 2 + 288, topBanner->position.y + 18);

	foodText = new Text();
	addChild(foodText);
	foodText->scale = Point(0.4f, 0.4f);
	foodText->position = Point(topBanner->position.x - topBanner->sprite()->size.x / 2 + 418, topBanner->position.y + 18);

	//add mainBuilding buttons
	numberOfBuildings = buildingList.size() - 1;
	for (int i = 0; i < numberOfBuildings; i++) {
		Point pos = Point(SWIDTH / 2 - (SWIDTH / 1.5) / 2.4 + i * buttonSize.x, SHEIGHT - (SHEIGHT / 6) / 1.9);
		mainButton = new CircleButton(buttonSize, pos, parent, i, player);
		mainButton->setColor(RGBAColor(0, 0, 0, 0));
		addChild(mainButton);
		mainButtonList.push_back(mainButton);
	}

	//add farm buttons
	Point buttonPos = Point(0, 0);
	//61 is the place of wheatfield in spritesheet
	wheatFieldButton = new CircleButton(buttonSize, buttonPos, parent, 61, player);
	//set the default color transparent
	wheatFieldButton->setColor(RGBAColor(0, 0, 0, 0));
	addChild(wheatFieldButton);
}

Hud::~Hud() {
	removeChild(topBanner);
	removeChild(bottomBanner);
	delete topBanner;
	delete bottomBanner;
}

void Hud::update(float deltaTime) {
	double mouseX = parent->input()->getMouseX();
	double mouseY = parent->input()->getMouseY();

	double bottomBannerRight = bottomBanner->position.x + bottomBanner->sprite()->size.x / 2;
	double bottomBannerLeft = bottomBanner->position.x - bottomBanner->sprite()->size.x / 2;
	double bottomBannerTop = bottomBanner->position.y - bottomBanner->sprite()->size.y;

	if (mouseX < bottomBannerRight && mouseX > bottomBannerLeft && mouseY > bottomBannerTop) {
		hoverHud = true;
	}
	else {
		hoverHud = false;
	}

	int s = mainButtonList.size();
	//Set the pos out of screen to avoid click collision.
	for (int i = 0; i < s; i++) {
		mainButtonList[i]->setPos(Point(0, -100));
	}
	wheatFieldButton->setPos(Point(0, -100));

	//if no building is selected
	if (selectedMenu == 0) {
		for (int i = 0; i < s; i++) {
			mainButtonList[i]->setColor(WHITE);
			mainButtonList[i]->setPos(Point(SWIDTH / 2 - (SWIDTH / 1.5) / 2.4 + i * buttonSize.x, SHEIGHT - (SHEIGHT / 6) / 1.9));
		}
	}
	if (selectedMenu == 1) {
		wheatFieldButton->setColor(WHITE);
		wheatFieldButton->setPos(Point(SWIDTH / 2 - (SWIDTH / 1.5) / 2.4, SHEIGHT - (SHEIGHT / 6) / 1.9));
	}

	string wood = "Wood: ";
	wood.append(rt2d::to_string<int>(player->wood));
	woodText->message(wood);

	string food = "Food: ";
	food.append(rt2d::to_string<int>(player->food));
	foodText->message(food);

	string gold = "Gold: ";
	gold.append(rt2d::to_string<int>(player->gold));
	goldText->message(gold);

	string stone = "Stone: ";
	stone.append(rt2d::to_string<int>(player->stone));
	stoneText->message(stone);
}
