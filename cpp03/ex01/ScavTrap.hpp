#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	
public:
	ScavTrap();
	ScavTrap( std::string name );
	ScavTrap( const ScavTrap &oldScavTrap );
	ScavTrap& operator= ( const ScavTrap &oldScavTrap );
	~ScavTrap();
	void guardGate( void );
};

#endif
