#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form( "presidentialPardon", 25, 5 )
	, target("default")
{}

PresidentialPardonForm::PresidentialPardonForm( const std::string& target )
	: Form( "presidentialPardon", 25, 5 )
	, target(target)
{}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &oldPresidentialPardonForm )
	: Form( "presidentialPardon", 25, 5 )
	, target(oldPresidentialPardonForm.target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator= ( const PresidentialPardonForm &oldPresidentialPardonForm )
{
	target = oldPresidentialPardonForm.target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

std::string PresidentialPardonForm::getTarget( void ) const
{
	return (target);
}

void PresidentialPardonForm::executeAction( void ) const
{
	std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
