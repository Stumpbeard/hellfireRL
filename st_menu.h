#ifndef ST_MENU_H
#define ST_MENU_H

#include "state.h"
#include "game.h"


struct Menu : State {
	
	Menu(Game* game);
	void update();
	void draw();
	
};

#endif