#include "Karen.hpp"

Karen::Karen()
{}

Karen::~Karen()
{}

void Karen::debug(void)
{
	std::cout << "(debug)    Are you sure this is vegan?" << std::endl;
}

void Karen::info(void)
{
	std::cout << "(info)     So what are the ingredients of the burger?!" << std::endl;
}

void Karen::warning(void)
{
	std::cout << "(warning)  If you can't tell and it looks like chicken then maybe you gave me chicken" << std::endl;
}

void Karen::error(void)
{
	std::cout << "(error)    I don't believe you! I don't trust you, you muuuurdereeer!!" << std::endl;
}

void Karen::complain(std::string level)
{
	std::string msgsFirstLetters = "DIWE";
	void (Karen::*messages[4])(void)
		= {
			&Karen::debug,
			&Karen::info,
			&Karen::warning,
			&Karen::error
		};
	std::size_t index = msgsFirstLetters.find(level.substr(0, 1));
	
	if (index != std::string::npos)
		(this->*messages[index])();
}
