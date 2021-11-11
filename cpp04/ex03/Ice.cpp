#include "Ice.hpp"

Ice::Ice()
{
	type = "ice";
}

Ice::Ice( const Ice &oldIce )
{
	type = oldIce.type;
}

Ice& Ice::operator= ( const Ice &oldIce )
{
	type = oldIce.type;
	return (*this);
}

Ice::~Ice()
{}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at "
		<< target.getName() << " *" << std::endl;
}
