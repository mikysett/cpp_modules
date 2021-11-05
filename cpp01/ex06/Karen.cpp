#include "Karen.hpp"

Karen::Karen()
{}

Karen::~Karen()
{}

void Karen::debug(void)
{
	std::cout << "[ DEBUG ]\nAre you sure this is vegan?" << std::endl;
}

void Karen::info(void)
{
	std::cout << "[ INFO ]\nSo what are the ingredients of the burger?!" << std::endl;
}

void Karen::warning(void)
{
	std::cout << "[ WARNING ]\nIf you can't tell and it looks like chicken then maybe you gave me chicken" << std::endl;
}

void Karen::error(void)
{
	std::cout << "[ ERROR ]\nI don't believe you! I don't trust you, you muuuurdereeer!!" << std::endl;
}

void Karen::complain(std::string level)
{
	std::string msgsFirstLetters = "DIWE";
	std::size_t index = std::string::npos;
	void (Karen::*messages[4])(void)
		= {
			&Karen::debug,
			&Karen::info,
			&Karen::warning,
			&Karen::error
		};
	
	if (level == "DEBUG"
		|| level == "INFO"
		|| level == "WARNING"
		|| level == "ERROR")
		index = msgsFirstLetters.find(level.substr(0, 1));
	switch (index)
	{
	case 0:
		(this->*messages[0])();
	case 1:
		(this->*messages[1])();
	case 2:
		(this->*messages[2])();
	case 3:
		(this->*messages[3])();
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
