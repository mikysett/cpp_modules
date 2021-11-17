#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
protected:
	const std::string name;
	const int gradeToSign;
	const int gradeToExecute;
	bool isSigned;

	void checkGrades( void ) const;
	void checkExecution( const Bureaucrat& executor ) const;
public:
	Form();
	Form( const std::string name, int gradeToSign, int gradeToExecute );
	Form( const Form &oldForm );
	Form& operator= ( const Form &oldForm );
	virtual ~Form();

	std::string getName( void ) const;
	int getGradeToSign( void ) const;
	int getGradeToExecute( void ) const;
	bool getIsSigned( void ) const;
	void beSigned( const Bureaucrat& bur );
	void execute( const Bureaucrat& executor ) const;
	virtual void executeAction( void ) const = 0;
	static Form *generate( const std::string target );

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what( void ) const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what( void ) const throw();
	};
	class NotSignedException : public std::exception
	{
		public:
			const char* what( void ) const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
