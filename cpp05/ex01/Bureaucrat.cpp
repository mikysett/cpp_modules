#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: name("labda bureaucrat")
	, grade(150)
{}

Bureaucrat::Bureaucrat( const std::string name )
	: name(name)
	, grade(150)
{}

Bureaucrat::Bureaucrat( const std::string name, int newGrade )
	: name(name)
{
	if (newGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (newGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade = newGrade;
}

Bureaucrat::Bureaucrat( const Bureaucrat &oldBureaucrat )
	: name(oldBureaucrat.name)
	, grade(oldBureaucrat.grade)
{}

Bureaucrat& Bureaucrat::operator= ( const Bureaucrat &oldBureaucrat )
{
	grade = oldBureaucrat.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

int Bureaucrat::getGrade( void ) const
{
	return (grade);
}

std::string const Bureaucrat::getName( void ) const
{
	return (name);
}

void Bureaucrat::incrementGrade()
{
	if (grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}

void Bureaucrat::signForm( Form& form ) const
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	} catch (std::exception& e)
	{
		std::cout << name << " couldn’t sign " << form.getName()
			<< " because " << e.what() << std::endl;
	}

}

const char* Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("Grade too low!");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& aBureaucrat)
{
	os << aBureaucrat.getName()
		<< ", bureaucrat grade " << aBureaucrat.getGrade();
	return (os);
}
