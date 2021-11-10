#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat: Default constructor" << std::endl;
}

Cat::Cat( const Cat &oldCat )
{
	type = oldCat.type;
	std::cout << "Cat: Constructor from other Cat object" << std::endl;
}

Cat& Cat::operator= ( const Cat &oldCat )
{
	std::cout << "Cat: Operator=" << std::endl;
	type = oldCat.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat: Default destructor" << std::endl;
}

void Cat::makeSound( void ) const
{
	std::cout << "Cat sound: miawwwwwww" << std::endl;
}
