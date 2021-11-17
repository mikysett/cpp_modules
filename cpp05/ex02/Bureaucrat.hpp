#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string const name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat( const std::string name );
	Bureaucrat( const std::string name, int newGrade );
	Bureaucrat( const Bureaucrat &oldBureaucrat );
	Bureaucrat& operator= ( const Bureaucrat &oldBureaucrat );
	~Bureaucrat();
	int getGrade( void ) const;
	std::string const getName( void ) const;
	void incrementGrade();
	void decrementGrade();
	void signForm( Form& form ) const;
	void executeForm( const Form& form );

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what(void) const throw ();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what(void) const throw ();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& aBureaucrat);

#endif
