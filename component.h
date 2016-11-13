#ifndef COMPONENT_H
#define COMPONENT_H

/* THE LOCATION OF COMPONENTS
	0	Position
	1	Tile
	2	Player Controllable
*/

#include <string>


struct Component
{
	virtual ~Component() {}
	std::string name;
};

#endif
