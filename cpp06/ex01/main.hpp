#ifndef MAIN_HPP
# define MAIN_HPP
# include <iostream>

struct Data {
	std::string firstName;
	std::string lastName;
	int age;
};

typedef unsigned long long uintptr_t;

uintptr_t serialize(const Data* ptr);
Data* deserialize(const uintptr_t raw);
void print_user(const Data& user);

#endif
