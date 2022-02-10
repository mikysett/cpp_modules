#include "Fixed.hpp"

Fixed::Fixed()
	: nb(0)
{}

Fixed::Fixed( const Fixed &oldNb )
{
	nb = oldNb.getRawBits();
}

Fixed::Fixed( const int intNb )
{
	nb = intNb << fractionalBits;
}

Fixed::Fixed( const float floatNb )
{
	nb = (int)roundf(floatNb * (1 << fractionalBits));
}

Fixed& Fixed::operator= ( const Fixed &oldNb )
{
	nb = oldNb.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits( void ) const
{
	return (nb);
}

void Fixed::setRawBits( int const raw )
{
	nb = raw;
}

float Fixed::toFloat( void ) const
{
	return (float)nb / (1 << fractionalBits);
}

int Fixed::toInt( void ) const
{
	return (nb >> fractionalBits);
}

std::ostream& operator<< ( std::ostream &outStream, const Fixed &objNb )
{
	outStream << objNb.toFloat();
	return (outStream);
}

bool Fixed::operator> ( const Fixed &otherPoint )
{
	return (nb > otherPoint.nb);
}

bool Fixed::operator< ( const Fixed &otherPoint )
{
	return (nb < otherPoint.nb);
}

bool Fixed::operator>= ( const Fixed &otherPoint )
{
	return (nb >= otherPoint.nb);
}

bool Fixed::operator<= ( const Fixed &otherPoint )
{
	return (nb <= otherPoint.nb);
}

bool Fixed::operator== ( const Fixed &otherPoint )
{
	return (nb == otherPoint.nb);
}

bool Fixed::operator!= ( const Fixed &otherPoint )
{
	return (nb != otherPoint.nb);
}


Fixed Fixed::operator+ ( const Fixed &otherPoint )
{
	Fixed newNb;

	newNb.setRawBits(nb + otherPoint.nb);
	return (newNb);
}

Fixed Fixed::operator- ( const Fixed &otherPoint )
{
	Fixed newNb;

	newNb.setRawBits(nb - otherPoint.nb);
	return (newNb);
}

Fixed Fixed::operator* ( const Fixed &otherPoint )
{
	Fixed newNb;

	newNb.setRawBits(nb * otherPoint.toFloat());
	return (newNb);
}

Fixed Fixed::operator/ ( const Fixed &otherPoint )
{
	Fixed newNb;

	newNb.setRawBits(nb / otherPoint.nb);
	return (newNb);
}


// Prefix operators
Fixed Fixed::operator++ ()
{
	++nb;
	return (*this);
}

Fixed Fixed::operator-- ()
{
	--nb;
	return (*this);
}

// Postfix operators
Fixed Fixed::operator++ (int)
{
	Fixed copyNb(*this);

	nb++;
	return (copyNb);
}

Fixed Fixed::operator-- (int)
{
	Fixed copyNb(*this);
	
	nb--;
	return (copyNb);
}

Fixed& Fixed::min( Fixed &a, Fixed&b )
{
	if (a.nb <= b.nb)
		return (a);
	return (b);
}

Fixed& Fixed::max( Fixed &a, Fixed&b )
{
	if (a.nb >= b.nb)
		return (a);
	return (b);
}


const Fixed& Fixed::min( const Fixed &a, const Fixed&b )
{
	if (a.nb <= b.nb)
		return (a);
	return (b);
}

const Fixed& Fixed::max( const Fixed &a, const Fixed&b )
{
	if (a.nb >= b.nb)
		return (a);
	return (b);
}

