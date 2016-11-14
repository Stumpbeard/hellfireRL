#ifndef COMP_TILE_H
#define COMP_TILE_H

#include "component.h"

struct Tile : Component
{
	Tile(int art, bool s, int scent, bool v = false) {this->art = art; solid = s; this->scent = scent; visible = v;}

	int art;
	int scent;
	bool solid;
	bool visible;

};

#endif
