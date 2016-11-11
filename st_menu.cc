#include "st_menu.h"
#include "st_inplay.h"
#include "global.h"
#include "curses.h"
#include <cstring>

using namespace std;

Menu::Menu(Game* game){
	this->game = game;
	selection = -2;

}

void Menu::update(){
	int c = getch();
	while(true){
		switch(c){
			case 'q':
				game->done = true;
				break;
			case 'n':
				game->states.push_back(new InPlay(game));
				break;
			case KEY_DOWN:
				if(selection == -2) selection++;
				selection++;
				break;
			case KEY_UP:
				if(selection > -1) selection--;
				break;
			case '\n':
				if(selection == 0){
					c = 'n';
					continue;
				}
				if(selection == 2){
					c = 'q';
					continue;
				}
				break;
		}
		break;
	}
	if(selection > 2) selection = 0;
	if(selection == -1) selection = 2;
}

void Menu::draw(){
	char title0[] = "          _______  _        _        _______ _________ _______  _______ ";
	char title1[] = "|\\     /|(  ____ \\( \\      ( \\      (  ____ \\\\__   __/(  ____ )(  ____ \\";
	char title2[] = "| )   ( || (    \\/| (      | (      | (    \\/   ) (   | (    )|| (    \\/";
	char title3[] = "| (___) || (__    | |      | |      | (__       | |   | (____)|| (__    ";
	char title4[] = "|  ___  ||  __)   | |      | |      |  __)      | |   |    	__)|  __)   ";
	char title5[] = "| (   ) || (      | |      | |      | (         | |   | (\\ (   | (      ";
	char title6[] = "| )   ( || (____/\\| (____/\\| (____/\\| )      ___) (___| ) \\ \\__| (____/\\";
	char title7[] = "|/     \\|(_______/(_______/(_______/|/       \\_______/|/   \\__/(_______/";

	mvprintw(SCREEN_HEIGHT/2 - 8, (SCREEN_WIDTH - strlen(title0))/2, "%s", title0);
	mvprintw(SCREEN_HEIGHT/2 - 7, (SCREEN_WIDTH - strlen(title1))/2, "%s", title1);
	mvprintw(SCREEN_HEIGHT/2 - 6, (SCREEN_WIDTH - strlen(title1))/2, "%s", title2);
	mvprintw(SCREEN_HEIGHT/2 - 5, (SCREEN_WIDTH - strlen(title1))/2, "%s", title3);
	mvprintw(SCREEN_HEIGHT/2 - 4, (SCREEN_WIDTH - strlen(title1))/2, "%s", title4);
	mvprintw(SCREEN_HEIGHT/2 - 3, (SCREEN_WIDTH - strlen(title1))/2, "%s", title5);
	mvprintw(SCREEN_HEIGHT/2 - 2, (SCREEN_WIDTH - strlen(title1))/2, "%s", title6);
	mvprintw(SCREEN_HEIGHT/2 - 1, (SCREEN_WIDTH - strlen(title1))/2, "%s", title7);

	char option0[] = "n) New Game";
	char option1[] = "c) Continue";
	char option2[] = "q) Quit";

	if(selection == 0){
		attron(COLOR_PAIR(1));
	}
	mvprintw(SCREEN_HEIGHT/2 + 3, (SCREEN_WIDTH - strlen(option0))/2, "%s", option0);
	attroff(COLOR_PAIR(1));
	if(selection == 1){
		attron(COLOR_PAIR(1));
	}
	mvprintw(SCREEN_HEIGHT/2 + 4, (SCREEN_WIDTH - strlen(option0))/2, "%s", option1);
	attroff(COLOR_PAIR(1));
	if(selection == 2){
		attron(COLOR_PAIR(1));
	}
	mvprintw(SCREEN_HEIGHT/2 + 6, (SCREEN_WIDTH - strlen(option0))/2, "%s", option2);
	attroff(COLOR_PAIR(1));

}
