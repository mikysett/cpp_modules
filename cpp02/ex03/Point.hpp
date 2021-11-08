#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
private:
	Fixed x;
	Fixed y;
public:
	Point();
	Point( const float a, const float b );
	Point( const Point &oldPoint );
	Point( const Fixed a, const Fixed b );
	Point& operator= ( const Point &oldPoint );
	~Point();
	const Fixed& getX() const;
	const Fixed& getY() const;
};

std::ostream& operator<< ( std::ostream& out, const Point& point);

#endif
