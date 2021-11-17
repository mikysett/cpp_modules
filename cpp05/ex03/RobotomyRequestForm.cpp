#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: Form( "robotomyRequest", 72, 45 )
	, target("default")
{}

RobotomyRequestForm::RobotomyRequestForm( const std::string& target )
	: Form( "robotomyRequest", 72, 45 )
	, target(target)
{}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &oldRobotomyRequestForm )
	: Form( "robotomyRequest", 72, 45 )
	, target(oldRobotomyRequestForm.target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator= ( const RobotomyRequestForm &oldRobotomyRequestForm )
{
	target = oldRobotomyRequestForm.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

std::string RobotomyRequestForm::getTarget( void ) const
{
	return (target);
}

void RobotomyRequestForm::executeAction( void ) const
{
	srand(time(0));
	const bool isSuccess = (bool)(rand() % 2);

	std::cout << "* bipbopbuubzzz *" << std::endl;
	if (!isSuccess)
		throw RobotomyRequestForm::FailToRobotomize();
	else
		std::cout << target << " has been robotomized" << std::endl;
}

const char* RobotomyRequestForm::FailToRobotomize::what( void ) const throw()
{
	return ("Can't robotomize the form");
}
