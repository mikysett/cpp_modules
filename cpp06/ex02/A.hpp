#ifndef A_HPP
# define A_HPP
# include <iostream>
# include "Base.hpp"

class A : public Base
{
private:
	std::string name;
public:
	A();
	A( const A &oldA );
	A& operator= ( const A &oldA );
	~A();
};

#endif
