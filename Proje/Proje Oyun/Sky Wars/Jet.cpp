#include "jet.h"
#include "console.h"

Jet::Jet(COORDINATE BaseIn, int SpeedIn, int colorIn,int sideIn) : 
	Plane(BaseIn, SpeedIn, colorIn,sideIn)
{}



void Jet::Draw(Console& c, char ch, int color)
{
	for(int i = Base.y; i <= Base.y + 1; i++)
		for(int j = Base.x; j <= Base.x + 4; j++)
		{
			c.SetColor(j, i, color);
			c.PrintChar(j, i, ch);
		}
}
