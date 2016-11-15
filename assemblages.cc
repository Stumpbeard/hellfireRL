#include <cstdlib>

#include "assemblages.h"
#include "comp_position.h"
#include "comp_tile.h"
#include "comp_playerControllable.h"

Entity* makePlayer(int y, int x, int t, bool c){
	Entity* player = new Entity();

	player->components[0] = new Position(y, x);
	player->components[1] = new Tile(t, true, 32, true);
	player->components[2] = new PlayerControllable(c);
	return player;
}

Entity* makeGrass(int y, int x){
	Entity* grass = new Entity();
	int g = rand()%5;
	switch(g){
		case 0:
			g = ',';
			break;
		case 1:
			g = '.';
			break;
		case 2:
			g = '`';
			break;
		case 3:
			g = '\"';
			break;
		default:
			g = ' ';
			break;
	}
	grass->components[0] = new Position(y, x);
	grass->components[1] = new Tile(g, false, 0);

	return grass;

}
