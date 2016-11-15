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

	if(!vis) attron(COLOR_PAIR(2));
	mvaddch(y, x, tile);
	attroff(COLOR_PAIR(2));
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

void adjustLOS(Entity* ent, Map* curmap)
{
	Position* pc = dynamic_cast<Position*>(ent->components[0]);
	int y = pc->y;
	int x = pc->x;

	for(int i = 0; i < curmap->map.size(); ++i){
		Position* pt = dynamic_cast<Position*>(curmap->map[i]->components[0]);
		Tile* tt = dynamic_cast<Tile*>(curmap->map[i]->components[1]);
		int ty = pt->y;
		int tx = pt->x;

		if(ty >= y-5 && ty <= y+5)
		{
			if(tx >= x-5 && tx <= x+5)
			{
				tt->visible = true;
			}
			else
			 {
				tt->visible = false;
			}
		}
		else
		{
			tt->visible = false;
		}
	}
}

#endif
