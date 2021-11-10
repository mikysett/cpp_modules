#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat: Default constructor" << std::endl;
}

WrongCat::WrongCat( const WrongCat &oldWrongCat )
{
	type = oldWrongCat.type;
	std::cout << "WrongCat: Constructor from other WrongCat object" << std::endl;
}

WrongCat& WrongCat::operator= ( const WrongCat &oldWrongCat )
{
	std::cout << "WrongCat: Operator=" << std::endl;
	type = oldWrongCat.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Default destructor" << std::endl;
}
