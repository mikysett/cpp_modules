#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal( const Animal &oldAnimal );
	Animal& operator= ( const Animal &oldAnimal );
	virtual ~Animal();

	std::string getType( void ) const;
	virtual void makeSound( void ) const = 0;
};

#endif
