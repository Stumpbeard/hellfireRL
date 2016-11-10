#include "st_menu.h"
#include "global.h"
#include "curses.h"
#include <cstring>

using namespace std;

Menu::Menu(Game* game){
	this->game = game;
	
}

void Menu::update(){

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

}