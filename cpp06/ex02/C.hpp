#ifndef C_HPP
# define C_HPP
# include <iostream>
# include "Base.hpp"

class C : public Base
{
private:
	std::string name;
public:
	C();
	C( const C &oldC );
	C& operator= ( const C &oldC );
	~C();
};

#endif
