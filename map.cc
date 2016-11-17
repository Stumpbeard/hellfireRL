#include "map.h"
#include "assemblages.h"
#include <fstream>

using namespace std;

Map::Map(){
	ifstream fin;
	fin.open("rogueEncampment.map", ifstream::in);
	char mapc = 0;

	map.resize(SCREEN_HEIGHT);
	for(int i = 0; i < SCREEN_HEIGHT; ++i)
		map[i].resize(SCREEN_WIDTH);
	for(int y = 0; y < SCREEN_HEIGHT; ++y)
		for(int x = 0; x < SCREEN_WIDTH; ++x){
			fin >> mapc;
			if(mapc == 'g') map[y][x] = makeGrass(y, x);
			if(mapc == 'w') map[y][x] = makePillar(y, x);
			/*if(y == 20 && x == 20) map[y][x] = makePillar(y, x);
			else map[y][x] = makeGrass(y, x);*/
		}

	fin.close();
}
