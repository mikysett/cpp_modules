#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain( const Brain &oldBrain )
{
	std::cout << "Brain copy constructor" << std::endl;
}

Brain& Brain::operator= ( const Brain &oldBrain )
{
	std::cout << "Brain operator=" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}
