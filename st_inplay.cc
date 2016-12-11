#include "st_inplay.h"
#include "curses.h"
#include "assemblages.h"
#include "systems.h"
#include "comp_position.h"
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
	entities.push_back(makeGoblin(12, 12));
	adjustLOS(player, maps.back(), entities);
	nocbreak();
	cbreak();


}

void InPlay::update(){
	playerControl(player, maps.back(), entities);
	adjustLOS(player, maps.back(), entities);
}

void InPlay::draw(){
	for(int y = 0; y < SCREEN_HEIGHT; ++y){
		for(int x = 0; x < SCREEN_WIDTH; ++x)
			displayEnt(maps.back()->map[y][x], maps.back());
	}
	for(int i = 0; i < entities.size(); ++i){
		mvprintw(0, 10, "Goblin printed and solid: %i", dynamic_cast<Tile*>(entities[0]->components[1])->solid);
		displayEnt(entities[i], maps.back());
	}
	displayEnt(player, maps.back());
	Position* p = dynamic_cast<Position*>(player->components[0]);
	mvprintw(0, 0, "%i, %i", p->y, p->x);
}
