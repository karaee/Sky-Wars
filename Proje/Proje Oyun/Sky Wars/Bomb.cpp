#include "Bomb.h"
#include "console.h"

Bomb::Bomb(COORDINATE BaseIn, Console& ConsoleIn) : Shots(BaseIn, ConsoleIn) {
	Draw(ConsoleIn, 223);
}

Bomb::~Bomb() {};

void Bomb::Move(Console& ConsoleIn) {
	if (!TimeIsUp()) {
		return; 
	}
	Erase(ConsoleIn);
	Base.y++;
	Draw(ConsoleIn, 223);
}

bool Bomb::IsDead()
{
	return (Base.y >= 21);
}
