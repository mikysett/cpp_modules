#include "Cure.hpp"

Cure::Cure()
{
	type = "cure";
}

Cure::Cure( const Cure &oldCure )
{
	type = oldCure.type;
}

Cure& Cure::operator= ( const Cure &oldCure )
{
	type = oldCure.type;
	return (*this);
}

Cure::~Cure()
{}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals "
		<< target.getName() << "'s wounds *" << std::endl;
}
