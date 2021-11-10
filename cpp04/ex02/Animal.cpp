#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal: Default constructor" << std::endl;
}

Animal::Animal( const Animal &oldAnimal )
	: type(oldAnimal.type)
{
	std::cout << "Animal: Constructor from other Animal object" << std::endl;
}

Animal& Animal::operator= ( const Animal &oldAnimal )
{
	std::cout << "Animal: Operator=" << std::endl;
	type = oldAnimal.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal: Default destructor" << std::endl;
}

std::string Animal::getType( void ) const
{
	return (type);
}

void Animal::makeSound( void ) const
{
	std::cout << "Animal sound" << std::endl;
}
