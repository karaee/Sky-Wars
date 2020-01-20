#ifndef PLANE_H
#define PLANE_H

class Console;
class Bomb;

struct COORDINATE
{
	int x;
	int y;

	COORDINATE(int xIn, int yIn) : x(xIn), y(yIn) {}
	int getX() { return x; }
	int getY() { return y; }
};

class Plane
{
	int Speed;
	int SpeedCounter;
	int color;
	int side;

protected:
	COORDINATE Base;

	virtual void Draw(Console& c, char ch, int color) = 0;

public:
	Plane(COORDINATE BaseIn, int SpeedIn, int colorIn,int sideIn);

	void Erase(Console& c);
	void Draw(Console& c);

	virtual bool TimeIsUp(double GameSpeed);
	bool IsDead();
	void MoveLeft(double GameSpeed, Console& c);
	void MoveRight(double GameSpeed, Console& c);
	void Move(double GameSpeed, Console& c,int a);
	void Fire(Bomb** BombIn, Console& c);
	int getX() { return Base.getX(); }
	int getY() { return Base.getY(); }
	int getside();
};

#endif