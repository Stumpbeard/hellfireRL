#ifndef GAME_H
#define GAME_H

#include <vector>

#include "state.h"

struct State;

struct Game {


	Game();

	std::vector<State*> states;

	void play();

};

#endif
