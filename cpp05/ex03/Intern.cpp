#include "Intern.hpp"

Intern::Intern()
{
	initGenerators();
}

Intern::Intern( const Intern &oldIntern )
{
	(void)oldIntern;
	initGenerators();
}

Intern& Intern::operator= ( const Intern &oldIntern )
{
	(void)oldIntern;
	return (*this);
}

Intern::~Intern()
{
}

void Intern::initGenerators( void )
{
	formGenerators[0].formName = "shrubbery request";
	formGenerators[0].generator = generateShrubbery;
	formGenerators[1].formName = "Shrubbery creation form";
	formGenerators[1].generator = generateShrubbery;
	formGenerators[2].formName = "robotomy request";
	formGenerators[2].generator = generateRobotomy;
	formGenerators[3].formName = "Robotomy request form";
	formGenerators[3].generator = generateRobotomy;
	formGenerators[4].formName = "presidential pardon request";
	formGenerators[4].generator = generatePresidentialPardon;
	formGenerators[5].formName = "Presidential pardon form";
	formGenerators[5].generator = generatePresidentialPardon;
}

Form* Intern::makeForm( const std::string& formName, const std::string& formTarget )
{
	for (int i = 0; i < NB_GENERATORS; i++)
		if (formName == formGenerators[i].formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (formGenerators->generator(formTarget));
		}
	std::cout << "Sorry sir, can't find the form " << formName << " :(" << std::endl;
	return (0);
}

Form* Intern::generateShrubbery( const std::string& target )
{
	return (new ShrubberyCreationForm(target));
}

Form* Intern::generateRobotomy( const std::string& target )
{
	return (new RobotomyRequestForm(target));
}

Form* Intern::generatePresidentialPardon( const std::string& target )
{
	return (new PresidentialPardonForm(target));
}
