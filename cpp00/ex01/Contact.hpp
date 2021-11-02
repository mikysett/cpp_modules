#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
public:
	Contact();
	void initFields();
	void printShort();
	void printLong();
};

#endif
