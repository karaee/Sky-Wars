#define MaxObj 7
#define MaxLength 5
#define MaxX 65
#define MaxSpeed 20
#define SpeedChange 0.1
#define Slowest 0.1
#define Fastest 2

#include "manager.h"

Manager::Manager()
{
	Score = 0;
	Speed = 1.0;
	MySoldier = NULL;

	MyPlanes = new Plane*[MaxObj];

	for (int h = 0; h < MaxObj; h++) {
		MyPlanes[h] = NULL;
	}

	MyBlts = new Bullet*[4];
	for (int i = 0; i < 5; i++) {
		MyBlts[i] = NULL;
	}

	MyBomb = new Bomb*[40];
	for (int i = 0; i < 41; i++) {
		MyBomb[i] = NULL;
	}

	GenerateGround(c);
	CreateNewShape(0);
}

Manager::~Manager()
{
	for (int i = 0; i < MaxObj; i++)
		delete MyPlanes[i];
	delete[] MyPlanes;
	for (int i = 0; i <41; i++)
		delete MyBomb[i];
	delete[] MyBomb;
	for (int i = 0; i < 5; i++)
		delete MyBlts[i];
	delete[] MyBlts;
	delete[] MySoldier;
}

void Manager::CreateNewShape(int i)
{
	Plane* planep;
	int kind = rand() % 2;
	int side = rand() % 2;
	if (kind == 0 && side == 0)
		planep = new Normal(COORDINATE(0, 3 * (rand() % 3) + 1), 4, c.rgb_b(1, 0, 0, 1) | c.rgb_f(1, 0, 0, 0), 0);
	if (kind == 0 && side == 1)
		planep = new Normal(COORDINATE(80, 3 * (rand() % 3) + 1), 4, c.rgb_b(1, 0, 0, 1) | c.rgb_f(1, 0, 0, 0), 1);
	if (kind == 1 && side == 0)
		planep = new Jet(COORDINATE(0, 3 * (rand() % 3) + 1), 1, c.rgb_b(1, 1, 1, 1) | c.rgb_f(1, 1, 0, 1), 0);
	if (kind == 1 && side == 1)
		planep = new Jet(COORDINATE(80, 3 * (rand() % 3) + 1), 1, c.rgb_b(1, 1, 1, 1) | c.rgb_f(1, 1, 0, 1), 1);
	if (MyPlanes[i])
		delete MyPlanes[i];

	MyPlanes[i] = planep;
}
void Manager::GenerateGround(Console& c) {
	for (int y = 22; y < 25; y++)
		for (int x = 0; x < 80;x++)
		{
			c.SetColor(x, y, 105);
			c.PrintChar(x, y, 'o');
		}
}


void Manager::Run()
{
	int g = 1;

	MySoldier = new Soldier(c, COORDINATE(40, 19));
	int condition = 1;
	while (condition != 2)
	{
		for (int i = 0; i < 2000000; i++) {}
		if (rand() % 800 == 0 && g < MaxObj)
		{
			CreateNewShape(g);
			g++;
		}

		if (_kbhit()){
			char ch = _getch();
			if ((ch == 'a') | (ch == 'd') | (ch == 'A') | (ch == 'D')) {
				MySoldier->Move(c, ch);
			}
			if ((ch == 'w') | (ch == 'W')) {
				MySoldier->Fire(MyBlts, c);
			}
			if ((ch == 'e') | (ch == 'E')) {
				_getch();
			}
		}

		int a = rand() % MaxObj;
			if (MyPlanes[a]&& rand()%60==0) {
				MyPlanes[a]->Fire(MyBomb, c);
			}

		for (int i = 0; i < 41; i++)
		{
			if (MyBomb[i] != NULL) {
				MyBomb[i]->Move(c);

				if (MyBomb[i]->IsDead()) {
					MyBomb[i]->Erase(c);
					delete MyBomb[i];
					MyBomb[i] = NULL;
				}
			}

		}

		for (int i = 0; i < 5; i++)
		{
			if (MyBlts[i]!=NULL) {
				MyBlts[i]->Move(c);

				if (MyBlts[i]->IsDead()) {
					delete MyBlts[i];
					MyBlts[i] = NULL;
				}
			}

		}

		for (int i = 0; i < MaxObj; i++)
		{
			if (MyPlanes[i]) {
				MyPlanes[i]->Move(Speed, c, MyPlanes[i]->getside());
				if (MyPlanes[i]->IsDead())
					CreateNewShape(i);
			}
		}
		for (int i = 0; i < MaxObj; i++)
		{
			for (int j = 0; j < 5; j++) {
				if (MyPlanes[i] && MyBlts[j]) {
					condition = 1;
					for (int a = 0; a < 2; a++) {
						for (int b = 0; b < 5; b++) {
							if (condition == 1 && MyPlanes[i]->getX() + b == MyBlts[j]->getX() && MyPlanes[i]->getY() + a == MyBlts[j]->getY())
							{
								MyPlanes[i]->Erase(c);
								CreateNewShape(i);
								MyBlts[j]->Erase(c);
								delete MyBlts[j];
								MyBlts[j] = NULL;
								Score++;
								condition = 0;
							}
						}
					}	
				}
			}
			for (int j = 0; j < 41; j++) {
				if (MyPlanes[i] && MyBomb[j]) {
					for (int b = -1; b < 2; b++) {
						if (MySoldier->getX() + b == MyBomb[j]->getX() && MySoldier->getY() == MyBomb[j]->getY())
						{
							condition = 2;
							
						}
					}
				}
			}
		}

		c.PrintText(0, 10, "Score Board");
		c.PrintChar(6, 11, 48+(Score%10));
		c.PrintChar(5, 11, 48 + ((Score/10) % 10));
		c.PrintChar(4, 11, 48 + ((Score / 100) % 10));

	}
	
	end(Score);
}

void Manager::end(int Score) {
	for (int i = 0; i < 81; i++)
		for (int j = 0; j < 22; j++)
			c.PrintChar(i, j, ' ');
	c.PrintText(35, 10, "GAME OVER!");
	c.PrintText(35, 11, "SCORE:");
	c.PrintChar(44, 11, 48 + (Score % 10));
	c.PrintChar(43, 11, 48 + ((Score / 10) % 10));
	c.PrintChar(42, 11, 48 + ((Score / 100) % 10));
	for (int i = 0; i < 999999999; i++)
	{

	}
}


