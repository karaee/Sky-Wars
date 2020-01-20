#include "Bullet.h"
#include "console.h"

Bullet::Bullet(COORDINATE BaseIn, Console& ConsoleIn) : Shots(BaseIn, ConsoleIn) {
		Draw(ConsoleIn,'|');
}

Bullet::~Bullet() {};

void Bullet::Move(Console& ConsoleIn) {
	if (!TimeIsUp()) {
		return;
	}
	Erase(ConsoleIn);	
	Base.y--;
	Draw(ConsoleIn, '|');
}

bool Bullet::IsDead()
{
	return (Base.y <= -1);
}

