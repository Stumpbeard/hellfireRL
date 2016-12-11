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
#include "comp_lineOfSight.h"

void displayEnt(Entity* ent, Map* m)
{
	Position* p = dynamic_cast<Position*>(ent->components[0]);
	Tile* t = dynamic_cast<Tile*>(ent->components[1]);
	PlayerControllable* pc = dynamic_cast<PlayerControllable*>(ent->components[2]);
	if(p == NULL || t == NULL){
		return;
	}

	int y = p->y;
	if(y < 0 || y >= SCREEN_HEIGHT) return;
	int x = p->x;
	if(x < 0 || x >= SCREEN_WIDTH) return;
	int tile = t->art;
	bool vis = t->visible;
	bool rev = t->revealed;

	bool isWall = false;

	if(tile == 'O') isWall = true;
	bool nW = false;
	bool sW = false;
	bool wW = false;
	bool eW = false;

	Tile* nWall = NULL;
	Tile* sWall = NULL;
	Tile* wWall = NULL;
	Tile* eWall = NULL;

	// find neighboring walls to change tile
	if(isWall){
		if(y-1 >= 0) nWall = dynamic_cast<Tile*>(m->map[y-1][x]->components[1]);
		if(y+1 <= SCREEN_HEIGHT-1) sWall = dynamic_cast<Tile*>(m->map[y+1][x]->components[1]);
		if(x-1 >= 0) wWall = dynamic_cast<Tile*>(m->map[y][x-1]->components[1]);
		if(x+1 <= SCREEN_WIDTH-1) eWall = dynamic_cast<Tile*>(m->map[y][x+1]->components[1]);

		if(nWall != NULL) nW = nWall->art == 'O' ? true : false;
		if(sWall != NULL) sW = sWall->art == 'O' ? true : false;
		if(wWall != NULL) wW = wWall->art == 'O' ? true : false;
		if(eWall != NULL) eW = eWall->art == 'O' ? true : false;

		if(sW && eW && nW && wW) tile = ACS_PLUS;
		else if(sW && eW && wW) tile = ACS_TTEE;
		else if(eW && nW && wW) tile = ACS_BTEE;
		else if(nW && eW && sW) tile = ACS_LTEE;
		else if(nW && wW && sW) tile = ACS_RTEE;
		else if(sW && eW) tile = ACS_ULCORNER;
		else if(nW && eW) tile = ACS_LLCORNER;
		else if(wW && sW) tile = ACS_URCORNER;
		else if(wW && nW) tile = ACS_LRCORNER;
		else if(nW && sW) tile = ACS_VLINE;
		else if(wW && eW) tile = ACS_HLINE;
		else tile = 'O';

		if(!vis && !rev) attron(COLOR_PAIR(2));
		else if(!vis) attron(COLOR_PAIR(3));
		mvaddch(y, x, tile);
		attroff(COLOR_PAIR(2));
		attroff(COLOR_PAIR(3));
	}

	else {
		if(!vis && !rev) attron(COLOR_PAIR(2));
		else if(!vis) attron(COLOR_PAIR(3));
		mvaddch(y, x, tile);
		attroff(COLOR_PAIR(2));
		attroff(COLOR_PAIR(3));
	}

	if(pc == NULL) t->visible = false;
}

void moveEnt(Entity* ent, int dir, Map* m)
{
	Position* p = dynamic_cast<Position*>(ent->components[0]);
	if(p == NULL){
		return;
	}

	if(dir == KEY_UP || dir == KEY_A2){
		if(p->y > 0)
			if(!dynamic_cast<Tile*>(m->map[p->y-1][p->x]->components[1])->solid)
				p->y--;
	}
	if(dir == KEY_DOWN || dir == KEY_C2){
		if(p->y < SCREEN_HEIGHT-1)
			if(!dynamic_cast<Tile*>(m->map[p->y+1][p->x]->components[1])->solid)
				p->y++;
	}
	if(dir == KEY_LEFT || dir == KEY_B1){
		if(p->x > 0)
			if(!dynamic_cast<Tile*>(m->map[p->y][p->x-1]->components[1])->solid)
				p->x--;
	}
	if(dir == KEY_RIGHT || dir == KEY_B3){
		if(p->x < SCREEN_WIDTH-1)
			if(!dynamic_cast<Tile*>(m->map[p->y][p->x+1]->components[1])->solid)
				p->x++;
	}
}

void playerControl(Entity* ent, Map* m, std::vector<Entity*> entList)
{
	Position* pp = dynamic_cast<Position*>(ent->components[0]);
	PlayerControllable* pc = dynamic_cast<PlayerControllable*>(ent->components[2]);
	if( pc == NULL || pp == NULL) return;

	int py = pp->y;
	int px = pp->x;

	int c = getch();
	bool entBreak = false; // Whether an entity gets in the way
	switch(c){
		case KEY_UP:
			for(int i = 0; i < entList.size(); ++i){
				Tile* entT = dynamic_cast<Tile*>(entList[i]->components[1]);
				Position* entP = dynamic_cast<Position*>(entList[i]->components[0]);
				if(entT != NULL && entP != NULL){
					if(entP->y == py-1 && entP->x == px && entT->solid == true){
						entBreak = true;
					}
				}
			}
			if(!entBreak) moveEnt(ent, KEY_UP, m);
			break;
		case KEY_DOWN:
			for(int i = 0; i < entList.size(); ++i){
				Tile* entT = dynamic_cast<Tile*>(entList[i]->components[1]);
				Position* entP = dynamic_cast<Position*>(entList[i]->components[0]);
				if(entT != NULL && entP != NULL){
					if(entP->y == py+1 && entP->x == px && entT->solid == true){
						entBreak = true;
					}
				}
			}
			if(!entBreak) moveEnt(ent, KEY_DOWN, m);
			break;
		case KEY_LEFT:
			for(int i = 0; i < entList.size(); ++i){
				Tile* entT = dynamic_cast<Tile*>(entList[i]->components[1]);
				Position* entP = dynamic_cast<Position*>(entList[i]->components[0]);
				if(entT != NULL && entP != NULL){
					if(entP->y == py && entP->x == px-1 && entT->solid == true){
						entBreak = true;
					}
				}
			}
			if(!entBreak) moveEnt(ent, KEY_LEFT, m);
			break;
		case KEY_RIGHT:
			for(int i = 0; i < entList.size(); ++i){
				Tile* entT = dynamic_cast<Tile*>(entList[i]->components[1]);
				Position* entP = dynamic_cast<Position*>(entList[i]->components[0]);
				if(entT != NULL && entP != NULL){
					if(entP->y == py && entP->x == px+1 && entT->solid == true){
						entBreak = true;
					}
				}
			}
			if(!entBreak) moveEnt(ent, KEY_RIGHT, m);
			break;
		case 'q':
			done = true;
			break;
	}
}

void adjustLOS(Entity* ent, Map* curmap, std::vector<Entity*> entList) // NEED TO ADD ENTITIES LIST TO THIS AND MOVE SO PLAYER CAN SEE AND COLLIDE
{
	Position* pc = dynamic_cast<Position*>(ent->components[0]);
	LineOfSight* plos = dynamic_cast<LineOfSight*>(ent->components[3]);
	if(pc == NULL || plos == NULL) return;
	int py = pc->y;
	int px = pc->x;



	int los = plos->los;
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
			bool entBreak = false; // Whether an ent gets in the way

			int delta_x(x2 - x1);
		    // if x1 == x2, then it does not matter what we set here
		    signed char const ix((delta_x > 0) - (delta_x < 0));
		    delta_x = std::abs(delta_x) << 1;

		    int delta_y(y2 - y1);
		    // if y1 == y2, then it does not matter what we set here
		    signed char const iy((delta_y > 0) - (delta_y < 0));
		    delta_y = std::abs(delta_y) << 1;

			Tile* bt = dynamic_cast<Tile*>(curmap->map[y1][x1]->components[1]);
			if(bt == NULL) continue;
			bt->visible = true;
			bt->revealed = true;
			for(int z = 0; z < entList.size(); ++z){
				Tile* entT = dynamic_cast<Tile*>(entList[z]->components[1]);
				Position* entP = dynamic_cast<Position*>(entList[z]->components[0]);
				if(entT != NULL && entP != NULL){
					if(entP->y == y1 && entP->x == x1){
						entT->visible = true;
						entT->revealed = true;
						if(entT->solid) entBreak = true;
					}
					//if(entT->solid) break;
				}
			}
			if(entBreak) break;

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

					Tile* bt = dynamic_cast<Tile*>(curmap->map[y1][x1]->components[1]);
					if(bt == NULL) continue;
					bt->visible = true;
					bt->revealed = true;
					for(int z = 0; z < entList.size(); ++z){
						Tile* entT = dynamic_cast<Tile*>(entList[z]->components[1]);
						Position* entP = dynamic_cast<Position*>(entList[z]->components[0]);
						if(entT != NULL && entP != NULL){
							if(entP->y == y1 && entP->x == x1){
								entT->visible = true;
								entT->revealed = true;
								if(entT->solid) entBreak = true;
							}
							// if(entT->solid) break;
						}
					}
					if(entBreak) break;
					if(bt->solid) break;

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

					Tile* bt = dynamic_cast<Tile*>(curmap->map[y1][x1]->components[1]);
					if(bt == NULL) continue;
					bt->visible = true;
					bt->revealed = true;
					for(int z = 0; z < entList.size(); ++z){
						Tile* entT = dynamic_cast<Tile*>(entList[z]->components[1]);
						Position* entP = dynamic_cast<Position*>(entList[z]->components[0]);
						if(entT != NULL && entP != NULL){
							if(entP->y == y1 && entP->x == x1){
								entT->visible = true;
								entT->revealed = true;
								if(entT->solid)  entBreak = true;
							}
							// if(entT->solid) break;
						}
					}
					if(entBreak) break;
					if(bt->solid) break;
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
