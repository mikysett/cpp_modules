#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>


class Fixed
{
private:
	int nb;
	static const int fractionalBits = 8;
public:
	Fixed();
	Fixed( const int intNb );
	Fixed( const float floatNb );
	Fixed( const Fixed &oldNb );
	Fixed& operator= ( const Fixed& oldNb );
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<< ( std::ostream& outStream, const Fixed& objNb );

#endif
