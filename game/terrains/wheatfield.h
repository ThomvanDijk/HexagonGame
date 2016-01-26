/**
* - Copyright 2015 Your Name <you@yourhost.com>
*     - Initial commit
*/

#ifndef WHEATFIELD_H
#define WHEATFIELD_H

#include "../terrain.h"

using namespace std;

class WheatField : public Terrain {
	public:
		WheatField();
		virtual ~WheatField();
		virtual void update(float deltaTime);

	private:
		bool placed;

};

#endif /* WHEATFIELD_H */ 
