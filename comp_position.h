#ifndef COMP_POSITION_H
#define COMP_POSITION_H

#include "component.h"

struct Position : Component
{
	Position(int y, int x) {this->y = y; this->x = x; name = "Position";}

	int y, x;
};

#endif
