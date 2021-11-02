#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int	main(void)
{
	std::string command;
	PhoneBook myPhoneBook;
	
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
	std::cin >> command;
	while (command != "EXIT")
	{
		if (command == "ADD")
			myPhoneBook.addContact();
		else if (command == "SEARCH")
			myPhoneBook.searchContact();
		else
			std::cout << "Invalid command, try again" << std::endl;
		std::cin >> command;
	}
}
