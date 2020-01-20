#pragma once
#include "Plane.h"

class Console;

class Shots {

	int SpeedCounter;
protected:
	COORDINATE Base;
	bool TimeIsUp();
public:
	Shots(COORDINATE BaseIn, Console& ConsoleIn);
	~Shots();
	virtual void  Move(Console& c) = 0;
	void Draw(Console& ConsoleIn, char c);
	void Erase(Console& ConsoleIn);
	int getX() { return Base.getX(); }
	int getY() { return Base.getY(); }
	virtual bool IsDead() = 0;
};