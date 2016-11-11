#ifndef ASSEMBLAGES_H
#define ASSEMBLAGES_H

#include "entity.h"
#include "comp_position.h"
#include "comp_tile.h"
#include "comp_playerControllable.h"

Entity* makePlayer(int y, int x, int t, bool c){
	Entity* player = new Entity();

	player->components[0] = new Position(y, x);
	player->components[1] = new Tile(t);
	player->components[2] = new PlayerControllable(c);
	return player;
}

#endif
