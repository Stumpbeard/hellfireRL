#include "curses.h"
#include "game.h"
#include "global.h"
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int mapScreen[SCREEN_HEIGHT][SCREEN_WIDTH];
int blanking[SCREEN_HEIGHT][SCREEN_WIDTH];

int revealed = 0;
void rerollMap();



int main()
{
	
	srand(time(NULL));
	
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	halfdelay(1);
	keypad(stdscr, 1);
	
	Game game;
	game.play();
	endwin();
	
}

void rerollMap(){
	for(int y = 0; y < SCREEN_HEIGHT; ++y){
		for(int x = 0; x < SCREEN_WIDTH; ++x){
			mapScreen[y][x] = rand()%(126-33)+33;
		}
	}
	
	
	for(int y = 0; y < SCREEN_HEIGHT; ++y){
		for(int x = 0; x < SCREEN_WIDTH; ++x){
			mvaddch(y, x, mapScreen[y][x]);
		}
	}
	
	int offset = revealed;
	for(int y = 0; y < revealed; ++y){
		for(int x = offset; x >= 0; --x){
			if(y >= SCREEN_HEIGHT) y = SCREEN_HEIGHT-1;
			mvaddch(y, x, blanking[y][x]);
		}
		--offset;
	}
	revealed += 2;
	
	
	char instr[] = " Press Q to Quit ";
	mvprintw(SCREEN_HEIGHT/2-1, (SCREEN_WIDTH-strlen(instr))/2, "%s", instr);
	move(SCREEN_HEIGHT/2-2, (SCREEN_WIDTH-strlen(instr))/2);
	for(int i = 0; i < strlen(instr); ++i){
		addch(' ');
	}
	move(SCREEN_HEIGHT/2, (SCREEN_WIDTH-strlen(instr))/2);
	for(int i = 0; i < strlen(instr); ++i){
		addch(' ');
	}
}