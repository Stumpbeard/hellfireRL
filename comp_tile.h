#ifndef COMP_TILE_H
#define COMP_TILE_H

#include "component.h"

struct Tile : Component
{
	Tile(int tile) {this->tile = tile;}

	int tile;
};

#endif
