#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	std::string target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm( const std::string& target );
	PresidentialPardonForm( const PresidentialPardonForm &oldPresidentialPardonForm );
	PresidentialPardonForm& operator= ( const PresidentialPardonForm &oldPresidentialPardonForm );
	~PresidentialPardonForm();

	std::string getTarget( void ) const;
	void executeAction( void ) const;
};

#endif
