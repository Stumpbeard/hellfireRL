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
	adjustLOS(player, maps.back());
	nocbreak();
	cbreak();


}

void InPlay::update(){
	playerControl(player);
	adjustLOS(player, maps.back());
}

void InPlay::draw(){
	for(int y = 0; y < SCREEN_HEIGHT; ++y){
		for(int x = 0; x < SCREEN_WIDTH; ++x)
			displayEnt(maps.back()->map[y][x]);
	}
	displayEnt(player);
}
