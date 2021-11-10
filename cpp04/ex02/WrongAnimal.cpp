#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal: Default constructor" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &oldWrongAnimal )
	: type(oldWrongAnimal.type)
{
	std::cout << "WrongAnimal: Constructor from other WrongAnimal object" << std::endl;
}

WrongAnimal& WrongAnimal::operator= ( const WrongAnimal &oldWrongAnimal )
{
	std::cout << "WrongAnimal: Operator=" << std::endl;
	type = oldWrongAnimal.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Default destructor" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
	return (type);
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal sound" << std::endl;
}
