/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#include "gamescene.h"
#include "superscene.h"
#include "player.h"

using namespace std;

GameScene::GameScene() : SuperScene() {
	origin = new Point2(SWIDTH / 2, SHEIGHT / 2);
	turn = 0;

	//The padding is -0.67f because I got problems with the borders of the hexes looking black.
	grid = new Grid(this, origin, 50, 20, -0.67f);
	addChild(grid);

	grid->addPlayerList(playerList);

	//Text doesn't work for now..
	/*std::string turnText = "Turn: ";
	turnText.append(std::to_string(turn));

	text[1]->message("TESTETETST");
	text[1]->position = Point2(SWIDTH / 2 - 300, SHEIGHT / 2 - 250);
	text[1]->scale = Point2(1, 1);*/
}

GameScene::~GameScene() {
	removeChild(grid);
	delete grid;
}

void GameScene::update(float deltaTime) {
	SuperScene::moveCamera(deltaTime);

	int s = playerList.size();
	for (int i = 0; i < s; i++) {
		if (playerList[i]->getActive() && !playerList[i]->getStarted()) {
			grid->setActivePlayer(i);
			//cout << "test" << endl;
		}
	}
}