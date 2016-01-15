/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#ifndef GRID
#define GRID

#include <rt2d/timer.h>
#include <rt2d/scene.h>
#include <vector>
#include "basicentity.h"
#include "hexagon.h"
#include "player.h"

using namespace std;

class Grid: public Entity {
	public:
		Grid(Scene* parent, Point2* origin, int size, int hexRadius, float padding, vector<Player*> playerList);
		virtual ~Grid();
		virtual void update(float deltaTime);
		virtual void gridRules(float deltaTime);
		virtual void setActivePlayer(int a) { activePlayer = a; }

	private:
		vector<Player*> playerList;
		RGBAColor playerColor;
		Timer timer;
		Scene* parent;
		Point2* origin;
		Hexagon* hexagon;
		int hexRadius;
		int owner; //0 = nobody, 1 = player1, 2 = player2, etc..
		int lastHovered;
		int activePlayer;
};

#endif /* GRID */ 
