#ifndef ASSEMBLAGES_H
#define ASSEMBLAGES_H

#include "entity.h"

Entity* makePlayer(int y, int x, int t, bool c);

Entity* makeGrass(int y, int x);
Entity* makePillar(int y, int x);

#endif
