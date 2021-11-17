#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include <cstdlib>
# include <ctime>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	std::string target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm( const std::string& target );
	RobotomyRequestForm( const RobotomyRequestForm &oldRobotomyRequestForm );
	RobotomyRequestForm& operator= ( const RobotomyRequestForm &oldRobotomyRequestForm );
	~RobotomyRequestForm();

	std::string getTarget( void ) const;
	void executeAction( void ) const;

	class FailToRobotomize : public std::exception
	{
		public:
			const char* what( void ) const throw();
	};
};

#endif
