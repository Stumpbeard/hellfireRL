#ifndef STATE_H
#define STATE_H

#include "game.h"

struct Game;

struct State {

	Game* game;
	virtual void update() = 0;
	virtual void draw() = 0;
};

#endif