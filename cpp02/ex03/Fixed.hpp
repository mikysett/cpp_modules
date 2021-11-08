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
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

	
	Fixed& operator= ( const Fixed& oldNb );

	bool operator> ( const Fixed &otherPoint );
	bool operator< ( const Fixed &otherPoint );
	bool operator>= ( const Fixed &otherPoint );
	bool operator<= ( const Fixed &otherPoint );
	bool operator== ( const Fixed &otherPoint );
	bool operator!= ( const Fixed &otherPoint );

	Fixed operator+ ( const Fixed &otherPoint );
	Fixed operator- ( const Fixed &otherPoint );
	Fixed operator* ( const Fixed &otherPoint );
	Fixed operator/ ( const Fixed &otherPoint );

	// Prefix operators
	Fixed operator++ ();
	Fixed operator-- ();
	// Postfix operators
	Fixed operator++ (int);
	Fixed operator-- (int);

	static Fixed& min( Fixed &a, Fixed&b );
	static Fixed& max( Fixed &a, Fixed&b );

	static const Fixed& min( const Fixed &a, const Fixed&b );
	static const Fixed& max( const Fixed &a, const Fixed&b );
};

std::ostream& operator<< ( std::ostream& outStream, const Fixed& objNb );

#endif
