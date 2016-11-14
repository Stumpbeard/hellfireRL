#include "map.h"
#include "assemblages.h"

Map::Map(){
	for(int y = 0; y < SCREEN_HEIGHT; ++y)
		for(int x = 0; x < SCREEN_WIDTH; ++x)
			map.push_back(makeGrass(y, x));

}
