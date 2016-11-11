#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "component.h"

struct Entity
{

	std::vector<Component*> components;
};

#endif
