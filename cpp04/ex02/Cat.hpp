#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat( const Cat &oldCat );
	Cat& operator= ( const Cat &oldCat );
	~Cat();

	void makeSound( void ) const;
private:
	Brain* brain;
};
#endif
