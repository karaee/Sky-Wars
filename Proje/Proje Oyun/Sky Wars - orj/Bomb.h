#pragma once

#include "Shots.h"
class Bomb : public Shots {

public:
	Bomb(COORDINATE BaseIn, Console& ConsoleIn);
	~Bomb();
	void Move(Console& ConsoleIn);

	bool IsDead();

};