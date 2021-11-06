#include "Fixed.hpp"

Fixed::Fixed()
	: nb(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &oldNb )
{
	std::cout << "Copy constructor called" << std::endl;
	nb = oldNb.getRawBits();
}

Fixed::Fixed( const int intNb )
{
	std::cout << "Int constructor called" << std::endl;
	nb = intNb << fractionalBits;
}

Fixed::Fixed( const float floatNb )
{
	std::cout << "Float constructor called" << std::endl;
	nb = (int)roundf(floatNb * (1 << fractionalBits));
}

Fixed& Fixed::operator= ( const Fixed &oldNb )
{
	std::cout << "Assignation operator called" << std::endl;
	nb = oldNb.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (nb);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
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
