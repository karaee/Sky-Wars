#ifndef SOLDIER_H
#define SOLDIER_H
#include "Plane.h"
class Bullet;
class Soldier {
	int direction;  // 1 for right, -1 for left
	COORDINATE Base;


public:
	Soldier(Console& c, COORDINATE BaseIn);
	void Draw(Console& c);
	void Erase(Console& c);
	void Fire(Bullet** BulletsIn, Console& c);
	int getX() { return Base.getX(); }
	int getY() { return Base.getY(); }
	void Move(Console& c,char ch);

};

#endif