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
#include "building.h"
#include "player.h"

//buildings
#include "buildings/towncenter.h"
#include "buildings/farm.h"

//terrains
#include "terrains/wheatfield.h"

using namespace std;

class Grid: public Entity {
	public:
		Grid(Scene* parent, Point2* origin, int size, int hexWidth, int hexHeight, float padding, Player* player);
		virtual ~Grid();
		virtual void update(float deltaTime);
		virtual void setHoverHud(bool h) { hoverHud = h; };
		virtual void setLoaded(bool b) { loaded = b; };
		virtual int getSelectedMenu() { return selectedMenu; };

	private:
		Player* player;
		Hexagon* hexagon;
		Scene* parent;
		Point2* origin;

		int lastHovered;
		int selectedMenu;
		Timer timer;
		bool loaded;
		bool hoverHud;
		int hexWidth;
		int hexHeight;

		int woodCost;
		int foodCost;
		int goldCost;
		int stoneCost;

		vector<Building*> buildingList;
		vector<Terrain*> terrainList;
		int selectedBuilding;

		//buildings
		TownCenter* townCenter;
		Farm* farm;

		//terrains
		WheatField* wheatField;

};

#endif /* GRID */
