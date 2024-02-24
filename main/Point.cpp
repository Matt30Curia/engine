#include "Point.h"


void Point::draw()
{
	// draw method using raylib
	DrawCircleV(pos.toVector2(), 3, BLACK);
}



