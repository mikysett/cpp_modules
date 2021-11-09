#ifndef FRAGTRAP_CPP
# define FRAGTRAP_CPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
	
public:
	FragTrap();
	FragTrap( std::string name );
	FragTrap( const FragTrap &oldFragTrap );
	FragTrap& operator= ( const FragTrap &oldFragTrap );
	~FragTrap();
	void highFivesGuys( void );
};

#endif
