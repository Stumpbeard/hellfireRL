#include "map.h"

Map::Map(int in[SCREEN_HEIGHT][SCREEN_WIDTH]){
	for(int y = 0; y < SCREEN_HEIGHT; ++y)
		for(int x = 0; x < SCREEN_WIDTH; ++x)
			map[y][x] = in[y][x];

}

int Map::tile(int y, int x){
	return map[y][x];
}
