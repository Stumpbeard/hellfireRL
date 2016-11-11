#ifndef C_PLAYERCONTROLLABLE_H
#define C_PLAYERCONTROLLABLE_H

#include "component.h"

struct PlayerControllable : Component
{
	PlayerControllable(bool controllable) {this->controllable = controllable;}

	bool controllable;
};

#endif
