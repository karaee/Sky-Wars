#pragma once
#include "Shots.h"
class Bullet: public Shots{

public:
	Bullet(COORDINATE BaseIn, Console& ConsoleIn);
	~Bullet();
	void Move(Console& ConsoleIn);

	bool IsDead();

};