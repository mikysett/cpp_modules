#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int	main(void)
{
	std::string command;
	PhoneBook myPhoneBook;
	
	while (command != "EXIT")
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT)" << std::endl;
		std::cin >> command;
		if (command == "ADD")
			myPhoneBook.addContact();
		else if (command == "SEARCH")
			myPhoneBook.searchContact();
		else if (command != "EXIT")
			std::cout << "Invalid command, try again" << std::endl;
	}
	return (0);
}
