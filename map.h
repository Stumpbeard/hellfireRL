#ifndef MAP_H
#define	MAP_H

#include "global.h"

struct Map {

	Map(int in[SCREEN_HEIGHT][SCREEN_WIDTH]);
	int map[SCREEN_HEIGHT][SCREEN_WIDTH];

	int tile(int y, int x);

};

#endif
