#include <iostream>

int	main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << "Address in memory of brain    : " << &brain << std::endl;
	std::cout << "Address in memory of stringPTR: " << stringPTR << std::endl;
	std::cout << "Address in memory of stringREF: " << &stringREF << std::endl;

	std::cout << "String in stringPTR: " << *stringPTR << std::endl;
	std::cout << "String in stringREF: " << stringREF << std::endl;
}
