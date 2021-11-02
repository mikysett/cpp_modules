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
	printBook();
}

void PhoneBook::printBook()
{
	for (int i = 0; i < nbContacts; i++)
	{
		contacts[i].printShort();
	}
}
