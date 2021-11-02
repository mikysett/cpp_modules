#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
private:
	int nbContacts;
	int oldestContact;
	Contact contacts[MAX_CONTACTS];
public:
	PhoneBook();
	void addContact();
	void searchContact();
	void printBook();
};

#endif
