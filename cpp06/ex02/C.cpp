#include "C.hpp"

C::C()
	:name("from base")
{
	std::cout << "Constructor from C (msg from class constructor)" << std::endl;
}

C::C( const C &oldC )
{
	name = oldC.name;
}

C& C::operator= ( const C &oldC )
{
	name = oldC.name;
	return (*this);
}

C::~C()
{}
