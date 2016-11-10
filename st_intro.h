#ifndef ST_INTRO_H
#define ST_INTRO_H

#include "state.h"
#include "global.h"
#include "curses.h"

struct Game;

struct Intro : State {
	
	int display[SCREEN_HEIGHT][SCREEN_WIDTH];
	int blank[SCREEN_HEIGHT][SCREEN_WIDTH*2];
	int sH, sW;
	int revealed;
	
	Intro(Game* game);
	void update();
	void draw();
	
};

#endif