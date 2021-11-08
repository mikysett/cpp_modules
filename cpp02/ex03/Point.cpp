#include "Point.hpp"

Point::Point()
	: x(Fixed())
	, y(Fixed())
{}

Point::Point( const float a, const float b )
	: x(Fixed(a))
	, y(Fixed(b))
{}

Point::Point( const Point &oldPoint )
	: x(oldPoint.x)
	, y(oldPoint.y)
{}

Point::Point( const Fixed a, const Fixed b )
	: x(a)
	, y(b)
{}

Point& Point::operator= ( const Point &oldPoint )
{
	x = oldPoint.x;
	y = oldPoint.y;
	return (*this);
}

Point::~Point()
{
}

const Fixed& Point::getX() const
{
	return (x);
}

const Fixed& Point::getY() const
{
	return (y);
}


std::ostream& operator<< ( std::ostream& out, const Point& point)
{
	out << "Point(" << point.getX().toFloat() << ", "
		<< point.getY().toFloat() << ")";
	return (out);
}
