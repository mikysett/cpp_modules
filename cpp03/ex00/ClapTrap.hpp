#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
private:
	std::string name;
	int hitpoints;
	int energyPoints;
	int attackDamage;
public:
	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( const ClapTrap &oldClapTrap );
	ClapTrap& operator= ( const ClapTrap &oldClapTrap );
	~ClapTrap();

	void attack( std::string const &target );
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );
};

#endif
