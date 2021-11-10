#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain( const Brain &oldBrain )
{
	for (int i = 0; i < 100; i++)
		ideas[i] = oldBrain.ideas[i];
	std::cout << "Brain copy constructor" << std::endl;
}

Brain& Brain::operator= ( const Brain &oldBrain )
{
	for (int i = 0; i < 100; i++)
		ideas[i] = oldBrain.ideas[i];
	std::cout << "Brain operator=" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}
