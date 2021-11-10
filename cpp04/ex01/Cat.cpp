#include "Cat.hpp"

Cat::Cat()
{
	brain = new Brain;
	type = "Cat";
	std::cout << "Cat: Default constructor" << std::endl;
}

Cat::Cat( const Cat &oldCat )
{
	brain = new Brain(*oldCat.brain);
	type = oldCat.type;
	std::cout << "Cat: Constructor from other Cat object" << std::endl;
}

Cat& Cat::operator= ( const Cat &oldCat )
{
	*brain = *oldCat.brain;
	type = oldCat.type;
	std::cout << "Cat: Operator=" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat: Default destructor" << std::endl;
}

void Cat::makeSound( void ) const
{
	std::cout << "Cat sound: miawwwwwww" << std::endl;
}
