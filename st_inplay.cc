#include "st_inplay.h"
#include "curses.h"
#include <cstdlib>

using namespace std;

InPlay::InPlay(Game* game){
	this->game = game;

	for(int y = 0; y < SCREEN_HEIGHT; ++y)
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
		}
	maps.push_back(new Map(display));

}

void InPlay::update(){
	int c = getch();
	switch(c){
		case 'q':
			game->done = true;
			break;
	}
}

void InPlay::draw(){
	for(int y = 0; y < SCREEN_HEIGHT; ++y){
		for(int x = 0; x < SCREEN_WIDTH; ++x){
			mvaddch(y, x, maps.back()->tile(y, x));
		}
	}
}
