#include "normal.h"
#include "console.h"

Normal::Normal(COORDINATE BaseIn, int SpeedIn, int colorIn,int sideIn) :
	Plane(BaseIn, SpeedIn, colorIn,sideIn)
{}




void Normal::Draw(Console& c, char ch, int color)
{
	for(int j = Base.x; j <= Base.x + 4; j++)
		for(int i = Base.y; i <= Base.y + 1; i++)
		{
			c.SetColor(j, i, color);

		}
}

