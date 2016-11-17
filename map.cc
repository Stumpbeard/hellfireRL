#include "map.h"
#include "assemblages.h"

Map::Map(){
	map.resize(SCREEN_HEIGHT);
	for(int i = 0; i < SCREEN_HEIGHT; ++i)
		map[i].resize(SCREEN_WIDTH);
	for(int y = 0; y < SCREEN_HEIGHT; ++y)
		for(int x = 0; x < SCREEN_WIDTH; ++x){
			if(y == 20 && x == 20) map[y][x] = makePillar(y, x);
			else map[y][x] = makeGrass(y, x);
		}
}
