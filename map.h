#ifndef MAP_H
#define	MAP_H

#include "global.h"
#include "entity.h"
#include <vector>
#include "assemblages.h"


struct Map {

	Map();
	std::vector< std::vector<Entity*> > map;

};

#endif
