#include "A.hpp"

A::A()
	:name("from base")
{
	std::cout << "Constructor from A (msg from class constructor)" << std::endl;
}

A::A( const A &oldA )
{
	name = oldA.name;
}

A& A::operator= ( const A &oldA )
{
	name = oldA.name;
	return (*this);
}

A::~A()
{}
