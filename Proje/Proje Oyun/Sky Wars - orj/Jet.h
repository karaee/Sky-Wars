#ifndef JET_H
#define JET_H

#include "plane.h"

class Console;

class Jet : public Plane
{
	

public:

	Jet(COORDINATE BaseIn, int SpeedIn, int colorIn,int sideIn);

	void Draw(Console& c, char ch, int color);
};

#endif