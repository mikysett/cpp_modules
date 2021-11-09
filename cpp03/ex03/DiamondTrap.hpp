#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;
public:
	DiamondTrap();
	DiamondTrap( std::string name );
	DiamondTrap( const DiamondTrap &oldDiamondTrap );
	DiamondTrap& operator= ( const DiamondTrap &oldDiamondTrap );
	~DiamondTrap();
	void whoAmI( void );
	virtual void attack( std::string const &target );
};

#endif
