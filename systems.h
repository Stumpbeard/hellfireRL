#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <cstdlib>
#include <cmath>
#include <algorithm>

#include "curses.h"
#include "entity.h"
#include "comp_position.h"
#include "comp_tile.h"
#include "comp_playerControllable.h"

void displayEnt(Entity* ent)
{
	Position* p = dynamic_cast<Position*>(ent->components[0]);
	Tile* t = dynamic_cast<Tile*>(ent->components[1]);
	PlayerControllable* pc = dynamic_cast<PlayerControllable*>(ent->components[2]);
	if(p == NULL || t == NULL){
		return;
	}

	int y = p->y;
	int x = p->x;
	int tile = t->art;
	bool vis = t->visible;
	bool rev = t->revealed;

	if(!vis && !rev) attron(COLOR_PAIR(2));
	else if(!vis) attron(COLOR_PAIR(3));
	mvaddch(y, x, tile);
	attroff(COLOR_PAIR(2));
	attroff(COLOR_PAIR(3));

	if(pc == NULL) t->visible = false;
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
	if(pc == NULL) return;
	int py = pc->y;
	int px = pc->x;



	int los = 5;
	for(int y = py-los; y <= py+los; ++y){
		if(y < 0 || y >= SCREEN_HEIGHT) continue;
		for(int x = px-los; x <= px+los; ++x){
			if(x < 0 || x >= SCREEN_WIDTH) continue;

			Tile* tt = dynamic_cast<Tile*>(curmap->map[y][x]->components[1]);
			if(tt == NULL) continue;

			int x1 = px;
			int y1 = py;
			const int x2 = x;
			const int y2 = y;

			int delta_x(x2 - x1);
		    // if x1 == x2, then it does not matter what we set here
		    signed char const ix((delta_x > 0) - (delta_x < 0));
		    delta_x = std::abs(delta_x) << 1;

		    int delta_y(y2 - y1);
		    // if y1 == y2, then it does not matter what we set here
		    signed char const iy((delta_y > 0) - (delta_y < 0));
		    delta_y = std::abs(delta_y) << 1;

			Tile* bt = dynamic_cast<Tile*>(curmap->map[y][x]->components[1]);
			if(bt == NULL) continue;
			bt->visible = true;
			bt->revealed = true;

		    if (delta_x >= delta_y)
		    {
		        // error may go below zero
		        int error(delta_y - (delta_x >> 1));

		        while (x1 != x2)
		        {
		            if ((error >= 0) && (error || (ix > 0)))
		            {
		                error -= delta_x;
		                y1 += iy;
		            }
		            // else do nothing

		            error += delta_y;
		            x1 += ix;

					Tile* bt = dynamic_cast<Tile*>(curmap->map[y][x]->components[1]);
					if(bt == NULL) continue;
					bt->visible = true;
					bt->revealed = true;
		        }
		    }
		    else
		    {
		        // error may go below zero
		        int error(delta_x - (delta_y >> 1));

		        while (y1 != y2)
		        {
		            if ((error >= 0) && (error || (iy > 0)))
		            {
		                error -= delta_y;
		                x1 += ix;
		            }
		            // else do nothing

		            error += delta_x;
		            y1 += iy;

					Tile* bt = dynamic_cast<Tile*>(curmap->map[y][x]->components[1]);
					if(bt == NULL) continue;
					bt->visible = true;
					bt->revealed = true;
		        }
		    }
		}
	}
}

				/* for(int y = 0; y < SCREEN_HEIGHT; ++y){
					for(int x = 0; x < SCREEN_WIDTH; ++x){
						Tile* tt = dynamic_cast<Tile*>(curmap->map[y][x]->components[1]);
						if(tt == NULL) continue;

						int ty = pt->y;
						int tx = pt->x;

						if(ty >= y-5 && ty <= y+5)
						{
							if(tx >= x-5 && tx <= x+5)
							{
								tt->visible = true;
								tt->revealed = true;
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
	} */

#endif
