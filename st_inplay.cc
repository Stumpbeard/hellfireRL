#include "st_inplay.h"
#include "curses.h"
#include "assemblages.h"
#include "systems.h"
#include <cstdlib>

using namespace std;

InPlay::InPlay(Game* game){
	this->game = game;
	player = makePlayer(10, 10, '@', true);

	/*for(int y = 0; y < SCREEN_HEIGHT; ++y)
		for(int x = 0; x < SCREEN_WIDTH; ++x){
			int grass = rand()%5;
			switch(grass){
				case 0:
					grass = ',';
					break;
				case 1:
					grass = '.';
					break;
				case 2:
					grass = '`';
					break;
				case 3:
					grass = '\"';
					break;
				default:
					grass = ' ';
					break;
			}
			display[y][x] = grass;
		} */
	maps.push_back(new Map());
	nocbreak();
	cbreak();


}

void InPlay::update(){
	playerControl(player);
}

void InPlay::draw(){
	for(int i = 0; i < maps.back()->map.size(); ++i){
		displayEnt(maps.back()->map[i]);
	}
	displayEnt(player);
}
