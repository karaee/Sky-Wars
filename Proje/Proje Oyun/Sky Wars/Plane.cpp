
#include <math.h>
#include "plane.h"
#include "console.h"
#include "Bomb.h"

Plane::Plane(COORDINATE BaseIn, int SpeedIn, int colorIn,int sideIn) : Base(BaseIn), Speed(SpeedIn), color(colorIn), side(sideIn)
{
	SpeedCounter=0;
}

void Plane::Fire(Bomb** BombIn, Console& ConsoleIn) {

	for (int i = 0; i <= 40; i++) {
		if ((BombIn[i] != NULL)) {
			continue;
		}
		BombIn[i] = new Bomb(COORDINATE(this->Base.x + 2, this->Base.y + 1), ConsoleIn);
		break;
	}

}
void Plane::Erase(Console& c)
{
	Draw(c, ' ', c.rgb_b(0,0,0,0) | c.rgb_f(0,0,0,0));
}
void Plane::Draw(Console& c)
{
	Draw(c, '.', color);
}
bool Plane::IsDead()
{
	return (Base.x == 90 || Base.x == -10);
}

bool Plane::TimeIsUp(double GameSpeed)
{
	if (ceil((double) Speed / GameSpeed) <= SpeedCounter)
	{
		SpeedCounter = 0;
		return true;
	}
	SpeedCounter++;
	return false;
}
void Plane:: MoveLeft(double GameSpeed, Console& c) {
	if (!TimeIsUp(GameSpeed))
		return;

	Erase(c);
	Base.x--;
	Draw(c);
}
void Plane:: MoveRight(double GameSpeed, Console& c) {
	if (!TimeIsUp(GameSpeed))
		return;

	Erase(c);
	Base.x++;
	Draw(c);
}
void Plane::Move(double GameSpeed, Console& c,int a)
{
	if (a == 0)
		MoveRight(GameSpeed, c);
	else
		MoveLeft(GameSpeed, c);
}
int Plane::getside() {
	return side;
}