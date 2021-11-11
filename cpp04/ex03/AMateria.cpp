#include "AMateria.hpp"

AMateria::AMateria()
{}

AMateria::AMateria( const AMateria &oldAMateria )
	: type(oldAMateria.type)
{}

AMateria& AMateria::operator= ( const AMateria &oldAMateria )
{
	type = oldAMateria.type;
	return (*this);
}

AMateria::~AMateria()
{}

std::string const& AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* a mateira used on "
		<< target.getName() << " *" << std::endl;
}
