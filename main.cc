#include "curses.h"
#include "game.h"
#include "global.h"
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

bool done = false;

int main()
{

	srand(time(NULL));

	initscr();
	noecho();
	cbreak();
	curs_set(0);
	halfdelay(1);
	keypad(stdscr, 1);

	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);

	Game game;
	game.play();
	endwin();

}
