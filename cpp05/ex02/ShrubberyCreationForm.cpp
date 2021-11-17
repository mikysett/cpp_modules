#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form( "shrubberyCreation", 145, 137 )
	, target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target )
	: Form( "shrubberyCreation", 145, 137 )
	, target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &oldShrubberyCreationForm )
	: Form( "shrubberyCreation", 145, 137 )
	, target(oldShrubberyCreationForm.target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator= ( const ShrubberyCreationForm &oldShrubberyCreationForm )
{
	target = oldShrubberyCreationForm.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

std::string ShrubberyCreationForm::getTarget( void ) const
{
	return (target);
}

void ShrubberyCreationForm::executeAction( void ) const
{
	std::ofstream outFile;
	std::string outFileName = target + "_shrubbery";

	outFile.open(outFileName.c_str());
	if (!outFile)
		throw ShrubberyCreationForm::FailCreateFile();
	outFile << "  **    ***  *" << std::endl
			<< " ****  ***** **" << std::endl
			<< "  ||    /  \\  !" << std::endl;
	outFile.close();
}

const char* ShrubberyCreationForm::FailCreateFile::what( void ) const throw()
{
	return ("Can't create the file ..._shrubbery");
}
