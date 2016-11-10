#include "st_intro.h"
#include "curses.h"
#include "game.h"
#include "global.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

Intro::Intro(){
	this->game = game;
	
	sH = SCREEN_HEIGHT;
	sW = SCREEN_WIDTH;
	revealed = 0;
	
	for(int y = 0; y < sH; ++y){
		for(int x = 0; x < sW*2; ++x){
			
		}
	}
	
}

void Intro::update(){
	for(int y = 0; y < sH; ++y){
		for(int x = 0; x < sW; ++x){
			display[y][x] = rand()%(126-33)+33;
		}
	}
	
}

void Intro::draw(){
	for(int y = 0; y < sH; ++y){
		for(int x = 0; x < sW; ++x){
			mvaddch(y, x, display[y][x]);
		}
	}
	
	int offset = revealed;
	for(int y = 0; y < revealed; ++y){
		for(int x = offset; x >= 0; --x){
			if(y >= SCREEN_HEIGHT) y = SCREEN_HEIGHT-1;
			mvaddch(y, x, ' ');
		}
		--offset;
	}
	revealed += 4;
}