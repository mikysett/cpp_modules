#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

// Tests taken from dda-silv repo, thanks dude ;)
int	main(void)
{
	Intern someRandomIntern;
	Form* form;

	form = someRandomIntern.makeForm("Presidential pardon form", "Bender");
	delete form;

	form = someRandomIntern.makeForm("Robotomy request form", "Bender");
	delete form;

	form = someRandomIntern.makeForm("Shrubbery creation form", "Bender");
	delete form;

	form = someRandomIntern.makeForm("Earth destruction request form", "Bender");
	return (0);
}
