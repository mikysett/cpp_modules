#include "B.hpp"

B::B()
	:name("from base")
{
	std::cout << "Constructor from B (msg from class constructor)" << std::endl;
}

B::B( const B &oldB )
{
	name = oldB.name;
}

B& B::operator= ( const B &oldB )
{
	name = oldB.name;
	return (*this);
}

B::~B()
{}