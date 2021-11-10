#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog: Default constructor" << std::endl;
}

Dog::Dog( const Dog &oldDog )
{
	type = oldDog.type;
	std::cout << "Dog: Constructor from other Dog object" << std::endl;
}

Dog& Dog::operator= ( const Dog &oldDog )
{
	std::cout << "Dog: Operator=" << std::endl;
	type = oldDog.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog: Default destructor" << std::endl;
}

void Dog::makeSound( void ) const
{
	std::cout << "Dog sound: baubaubau" << std::endl;
}
