#include "bsq.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	const float areaTriangle = doubleOfArea(a, b, c),
		a1 = doubleOfArea(point, b, c),
		a2 = doubleOfArea(a, point, c),
		a3 = doubleOfArea(a, b, point);
	
	if (a1 == 0 || a2 == 0 || a3 == 0
		|| a1 + a2 + a3 != areaTriangle)
		return (false);
	return (true);
}

float doubleOfArea(const Point &a, const Point &b, const Point &c)
{
	float area = a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
		+ b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())
		+ c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat());

	if (area < 0)
		area *= -1;
	return (area);
}