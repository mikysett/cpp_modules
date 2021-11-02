#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
	: nbContacts(0)
	, oldestContact(0)
{}

void PhoneBook::addContact()
{
	Contact newContact;

	newContact.initFields();
	if (nbContacts == MAX_CONTACTS)
	{
		contacts[oldestContact] = newContact;
		oldestContact = (oldestContact + 1) % MAX_CONTACTS;
	}
	else
	{
		contacts[nbContacts] = newContact;
		nbContacts++;
	}
}

void PhoneBook::searchContact()
{
	if (nbContacts == 0)
	{
		std::cout << "No contacts yet, use command ADD" << std::endl;
		return ;
	}
	printBook();
	std::cout << "Contact id to show: ";
	long contactId;
	std::cin >> contactId;
	if (std::cin.fail() || contactId < 0 || contactId >= nbContacts)
	{
		if (std::cin.fail())
			std::cin.clear();
		std::cout << "INVALID ID!" << std::endl;
	}
	else
		contacts[contactId].printLong();
}

void PhoneBook::printBook()
{
	std::cout << std::right << std::setw(10) << "INDEX" << "|"
		<< std::right << std::setw(10) << "FIRST NAME" << "|"
		<< std::right << std::setw(10) << "LAST NAME" << "|"
		<< std::right << std::setw(10) << "NICKNAME" << "|" << std::endl;
	for (int i = 0; i < nbContacts; i++)
	{
		std::cout << std::right << std::setw(10) << i << "|";
		contacts[i].printShort();
	}
}
