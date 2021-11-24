#include "main.hpp"

int	main(void)
{
	Data user1 = {
		.firstName = "Louis",
		.lastName = "Dupont",
		.age = 22
	};
	Data user2 = {
		.firstName = "Juliette",
		.lastName = "Lafayette",
		.age = 44
	};
	Data user3 = {
		.firstName = "Marianne",
		.lastName = "L.",
		.age = 33
	};

	print_user(user1);
	print_user(user2);
	print_user(user3);

	std::cout << std::endl << "The pointers" << std::endl;
	std::cout << serialize(&user1) << std::endl;
	std::cout << serialize(&user2) << std::endl;
	std::cout << serialize(&user3) << std::endl;

	std::cout << std::endl;
	std::cout << "magic nasty time" << std::endl;
	std::cout << "Results should show in the same order of before" << std::endl;
	std::cout << std::endl;
	
	uintptr_t ptr = serialize(&user1);
	print_user(*deserialize(ptr));
	print_user(*deserialize(serialize(&user2)));

	uintptr_t ptr_3 = serialize(&user3);
	Data* cpy_3 = deserialize(ptr_3);
	print_user(*cpy_3);

	return (0);
}

uintptr_t serialize(const Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(const uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

void print_user(const Data& user)
{
	std::cout
		<< user.firstName
		<< " "
		<< user.lastName
		<< ", age "
		<< user.age
		<< std::endl;
}
