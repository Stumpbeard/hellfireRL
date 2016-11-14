#ifndef SYSTEMS_H
#define SYSTEMS_H

#include "curses.h"
#include "entity.h"
#include "comp_position.h"
#include "comp_tile.h"
#include "comp_playerControllable.h"

void displayEnt(Entity* ent)
{
	Position* p = dynamic_cast<Position*>(ent->components[0]);
	Tile* t = dynamic_cast<Tile*>(ent->components[1]);
	if(p == NULL || t == NULL){
		return;
	}

	int y = p->y;
	int x = p->x;
	int tile = t->art;
	bool vis = t->visible;

	if(!vis) attron(A_DIM);
	mvaddch(y, x, tile);
	attroff(A_DIM);
}

void moveEnt(Entity* ent, int dir)
{
	Position* p = dynamic_cast<Position*>(ent->components[0]);
	if(p == NULL){
		return;
	}

	if(dir == KEY_UP) p->y--;
	if(dir == KEY_DOWN) p->y++;
	if(dir == KEY_LEFT) p->x--;
	if(dir == KEY_RIGHT) p->x++;
}

void playerControl(Entity* ent)
{
	PlayerControllable* pc = dynamic_cast<PlayerControllable*>(ent->components[2]);
	if( pc == NULL) return;

	int c = getch();
	switch(c){
		case KEY_UP:
			moveEnt(ent, KEY_UP);
			break;
		case KEY_DOWN:
			moveEnt(ent, KEY_DOWN);
			break;
		case KEY_LEFT:
			moveEnt(ent, KEY_LEFT);
			break;
		case KEY_RIGHT:
			moveEnt(ent, KEY_RIGHT);
			break;
		case 'q':
			done = true;
			break;
	}
}

#endif
