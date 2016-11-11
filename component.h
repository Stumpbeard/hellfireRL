#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>


struct Component
{
	virtual ~Component() {}
	std::string name;
};

#endif
