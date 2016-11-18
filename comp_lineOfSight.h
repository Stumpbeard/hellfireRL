#ifndef C_LINEOFSIGHT_H
#define C_LINEOFSIGHT_H

#include "component.h"

struct LineOfSight : Component
{
	LineOfSight(int los) {this->los = los;}

	int los;
};

#endif
