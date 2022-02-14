#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* theDog = new Dog();
	const Animal* theCat = new Cat();

	std::cout << theDog->getType() << " " << std::endl;
	std::cout << theCat->getType() << " " << std::endl;
	theDog->makeSound();
	theCat->makeSound(); //will output the cat sound!
	meta->makeSound();

	delete meta;
	delete theDog;
	delete theCat;

	std::cout << std::endl;

	const WrongAnimal* theWrongAnimal = new WrongAnimal();
	const WrongAnimal* theWrongCat = new WrongCat();

	std::cout << theWrongCat->getType() << " " << std::endl;
	theWrongCat->makeSound();
	theWrongAnimal->makeSound();
	
	const WrongCat wrongCatStatic = WrongCat();
	std::cout << "static wrong cat: " << std::endl;	
	wrongCatStatic.makeSound();

	delete theWrongAnimal;
	delete theWrongCat;
	return (0);
}
