#include "Contact.hpp"

	Contact::Contact() {};

	void Contact::initFields()
	{
		std::cout << "First name: ";
		std::getline(std::cin >> std::ws, firstName);
		std::cout << "Last name: ";
		std::getline(std::cin >> std::ws, lastName);
		std::cout << "Nickname: ";
		std::getline(std::cin >> std::ws, nickname);
		std::cout << "Phone number: ";
		std::getline(std::cin >> std::ws, phoneNumber);
		std::cout << "Darkest secret: ";
		std::getline(std::cin >> std::ws, darkestSecret);
		
	}
	
	void Contact::printShort()
	{
		printShortField(firstName);
		printShortField(lastName);
		printShortField(nickname);
		std::cout << std::endl;
	}

	void Contact::printShortField(std::string field)
	{
		if (field.length() <= 10)
			std::cout << std::right << std::setw(10) << field << "|";
		else
			std::cout << std::right << std::setw(9) << field.substr(0, 9) << ".|";
	}
	
	void Contact::printLong()
	{
		std::cout << "First name: " << firstName << std::endl
			<< "Last name: " << lastName << std::endl
			<< "Nickname: " << nickname << std::endl
			<< "Phone number: " << phoneNumber << std::endl
			<< "Darkest secret: " << darkestSecret << std::endl;
	}