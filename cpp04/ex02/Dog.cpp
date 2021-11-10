#include "Dog.hpp"

Dog::Dog()
{
	brain = new Brain;
	type = "Dog";
	std::cout << "Dog: Default constructor" << std::endl;
}

Dog::Dog( const Dog &oldDog )
{
	brain = new Brain(*oldDog.brain);
	type = oldDog.type;
	std::cout << "Dog: Constructor from other Dog object" << std::endl;
}

Dog& Dog::operator= ( const Dog &oldDog )
{
	*brain = *oldDog.brain;
	type = oldDog.type;
	std::cout << "Dog: Operator=" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog: Default destructor" << std::endl;
}

void Dog::makeSound( void ) const
{
	std::cout << "Dog sound: baubaubau" << std::endl;
}
