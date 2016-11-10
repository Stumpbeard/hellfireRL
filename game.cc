#include "game.h"
#include "st_intro.h"
#include "curses.h"
#include "global.h"
#include <iostream>

using namespace std;

Game::Game(){
	
	State* intro = new Intro();
	states.push_back(intro);
}

void Game::play(){
	
	
	resize_term(SCREEN_HEIGHT, SCREEN_WIDTH);
	
	
	bool done = false;
	int c;
	while(!done){
		clear();
		states.back()->update();
		states.back()->draw();
		refresh();
		c = getch();
		if(c == 'q') done = true;
	}
	
}