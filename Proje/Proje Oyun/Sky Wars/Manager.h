#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
using namespace std;


#include "console.h"
#include "normal.h"
#include "jet.h"
#include "Soldier.h"
#include "Bullet.h"
#include "Bomb.h"


class Plane;



class Manager
{
	Plane** MyPlanes;
	double Speed;
	Bullet** MyBlts;
	Bomb** MyBomb;
	Soldier* MySoldier;
	int Score;
	
	void end(int);
	void CreateNewShape(int i);
	void GenerateGround(Console& c);


public:
	Console c;
	Manager();
	~Manager();
	
	void Run();

};

#endif

