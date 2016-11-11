#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "component.h"

struct Entity
{
	Entity(){components.resize(3);}
	std::vector<Component*> components;
};

#endif
