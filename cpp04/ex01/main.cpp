#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int	main(void)
{
	int size = 10;
	const Animal* animals[size];

	std::cout << "Initialize the array" << std::endl;
	for (int i = 0; i < size; i++)
		i % 2 == 0 ? animals[i] = new Dog : animals[i] = new Cat;
	std::cout << std::endl;
	std::cout << "Make 3 deep copies" << std::endl;
	if (1)
	{
		Dog dog1;
		Cat cat1;
		Dog dogCopy1 = dog1;
		Cat catCopy2;
		catCopy2 = cat1;
		Dog dogCopy3 = dog1;
	}
	std::cout << std::endl;
	std::cout << "Destroy the array" << std::endl;
	for (int i = 0; i < size; i++)
		delete animals[i];
	return (0);
}
