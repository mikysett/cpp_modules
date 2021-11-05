#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
private:
	int nb;
	static const int fractionalBits = 8;
public:
	Fixed();
	Fixed( const Fixed &oldNb );
	Fixed& operator= ( const Fixed &oldNb );
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
