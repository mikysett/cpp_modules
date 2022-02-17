#include "Form.hpp"

Form::Form()
	: name("Unnamed")
	, gradeToSign(150)
	, gradeToExecute(150)
	, isSigned(false)
{}

Form::Form( const std::string name, int gradeToSign, int gradeToExecute )
	: name(name)
	, gradeToSign(gradeToSign)
	, gradeToExecute(gradeToExecute)
	, isSigned(false)
{
	checkGrades();
}

Form::Form( const Form &oldForm )
	: name(oldForm.name)
	, gradeToSign(oldForm.gradeToSign)
	, gradeToExecute(oldForm.gradeToExecute)
	, isSigned(oldForm.isSigned)
{}

Form& Form::operator= ( const Form &oldForm )
{
	isSigned = oldForm.isSigned;
	return (*this);
}

Form::~Form()
{}

std::string Form::getName( void ) const
{
	return (name);
}

int Form::getGradeToSign( void ) const
{
	return (gradeToSign);
}

int Form::getGradeToExecute( void ) const
{
	return (gradeToExecute);
}

bool Form::getIsSigned( void ) const
{
	return (isSigned);
}

void Form::beSigned(const Bureaucrat& bur)
{
	if (gradeToSign < bur.getGrade())
		throw Form::GradeTooLowException();
	else
		isSigned = true;
}

void Form::checkGrades( void ) const
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

void Form::execute( const Bureaucrat& executor ) const
{
	try
	{
		checkExecution(executor);
		executeAction();
	}
	catch(const std::exception& e)
	{
		throw;
	}
}

void Form::checkExecution( const Bureaucrat& executor ) const
{
	if (gradeToExecute < executor.getGrade())
		throw Form::GradeTooLowException();
	else if (!isSigned)
		throw Form::NotSignedException();
}

const char* Form::GradeTooHighException::what( void ) const throw()
{
	return ("Form: Grade too high");
}

const char* Form::GradeTooLowException::what( void ) const throw()
{
	return ("Form: Grade too low");
}

const char* Form::NotSignedException::what( void ) const throw()
{
	return ("Form: Document not signed");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form " << form.getName()
		<< ", grade to sign " << form.getGradeToSign()
		<< ", grade to execute " << form.getGradeToExecute()
		<< ", " << (form.getIsSigned() == true ? "is signed" : "is NOT signed");
	return (os);
}
