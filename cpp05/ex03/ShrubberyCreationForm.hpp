#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
	std::string target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm( const std::string& target );
	ShrubberyCreationForm( const ShrubberyCreationForm &oldShrubberyCreationForm );
	ShrubberyCreationForm& operator= ( const ShrubberyCreationForm &oldShrubberyCreationForm );
	~ShrubberyCreationForm();

	std::string getTarget( void ) const;
	void executeAction( void ) const;
	static Form* generate( const std::string& target );

	class FailCreateFile : public std::exception
	{
		public:
			const char* what( void ) const throw();
	};
};

#endif
