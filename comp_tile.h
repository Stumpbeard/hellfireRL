#ifndef COMP_TILE_H
#define COMP_TILE_H

#include "component.h"

struct Tile : Component
{
	Tile(int art, bool s, int scent, bool v = false, bool r = false) {this->art = art;
		solid = s; this->scent = scent; visible = v; revealed = r;}

	int art;
	int scent;
	bool solid;
	bool visible;
	bool revealed;

};

#endif
