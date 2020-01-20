#include "Shots.h"
#include "Console.h"
#include "Bullet.h"

Shots::Shots(COORDINATE BaseIn, Console& ConsoleIn):Base(BaseIn) {
	SpeedCounter = 0;
};

Shots::	~Shots() { }


void Shots::Draw(Console& ConsoleIn, char c){
	ConsoleIn.SetColor(Base.x, Base.y, ConsoleIn.rgb_f(0, 0, 0, 1));
	ConsoleIn.PrintChar(Base.x, Base.y, c);
}
void Shots::Erase(Console & ConsoleIn){
	ConsoleIn.SetColor(Base.x, Base.y, ConsoleIn.rgb_f(1, 1, 1, 1));
	ConsoleIn.PrintChar(Base.x, Base.y, ' ');
}
;


bool Shots::TimeIsUp()
{
	if (SpeedCounter>=15)
	{
		SpeedCounter = 0;
		return true;
	}
	SpeedCounter++;
	return false;
}

