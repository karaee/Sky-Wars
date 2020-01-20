#ifndef NORMAL_H
#define NORMAL_H

#include "plane.h"

class Console;

class Normal : public Plane
{
	

public:

	Normal(COORDINATE BaseIn, int SpeedIn, int colorIn,int sideIn);


	void Draw(Console& c, char ch, int color);
};

#endif