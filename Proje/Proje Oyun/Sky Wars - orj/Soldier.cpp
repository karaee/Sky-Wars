#include "soldier.h"
#include "console.h"
#include "Bullet.h"
Soldier::Soldier(Console& c, COORDINATE BaseIn):Base(BaseIn) {
	Draw(c);
	direction = 1;
}

void Soldier::Fire(Bullet** BulletsIn,Console& ConsoleIn) {

	for (int i = 0;  i <= 4 ; i++) {
		if ((BulletsIn[i]!=NULL)) {
			continue;
		}
		BulletsIn[i] = new Bullet(COORDINATE(this->Base.x + direction, this->Base.y - 1), ConsoleIn);
		break;
	}

}




void Soldier::Move(Console&c, char ch) {
	Erase(c);
	if ((ch == 'a'|ch== 'A') && (Base.x>1)) {
		Base.x--;
		if (direction == 1) { direction = -1; }

	}
	if ((ch == 'd' | ch == 'D') && (Base.x<78)) {
		Base.x++;
		if (direction == -1) { direction = 1; }

	}
		Draw(c);
}
void Soldier::Draw(Console& c) {
	

	c.PrintChar(Base.x, Base.y,'O');
	c.PrintChar(Base.x+direction, Base.y, 185 );
	c.SetColor(Base.x+direction, Base.y, c.rgb_b(0, 0, 0, 0) | c.rgb_f(1, 0, 0, 0));
	char Line2[4] = { (char)192,' ',(char)217,'\0' };
	c.PrintText(Base.x - 1, Base.y + 1,Line2);
	c.SetColor(Base.x, Base.y + 1, c.rgb_b(0, 1, 0, 0) | c.rgb_f(1, 1, 1, 1));
	c.PrintChar(Base.x, Base.y+2, 186);

}
void Soldier::Erase(Console& c) {
	c.PrintChar(Base.x, Base.y, ' ');
	c.PrintChar(Base.x + direction, Base.y, ' ');
	c.SetColor(Base.x + direction, Base.y, c.rgb_b(0, 0, 0, 0) | c.rgb_f(1, 1, 1, 1));
	c.PrintText(Base.x - 1, Base.y + 1, "   ");
	c.SetColor(Base.x, Base.y + 1, c.rgb_b(0, 0, 0, 0) | c.rgb_f(1, 1, 1, 1));
	c.PrintChar(Base.x, Base.y + 2, ' ');
}
