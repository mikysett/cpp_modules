#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Form.hpp"
# define NB_GENERATORS 6

class Intern
{
private:
	typedef struct s_pair
	{
		std::string formName;
		Form* (*generator)( const std::string& );
	}	t_pair;
	t_pair formGenerators[NB_GENERATORS];
public:
	Intern();
	Intern( const Intern &oldIntern );
	Intern& operator= ( const Intern &oldIntern );
	~Intern();

	void initGenerators( void );
	static Form* generateShrubbery( const std::string& target );
	static Form* generateRobotomy( const std::string& target );
	static Form* generatePresidentialPardon( const std::string& target );
	Form* makeForm( const std::string& formName, const std::string& formTarget );

};

#endif
