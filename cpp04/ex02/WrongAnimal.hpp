#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal( const WrongAnimal &oldWrongAnimal );
	WrongAnimal& operator= ( const WrongAnimal &oldWrongAnimal );
	virtual ~WrongAnimal();

	std::string getType( void ) const;
	void makeSound( void ) const;
};

#endif
