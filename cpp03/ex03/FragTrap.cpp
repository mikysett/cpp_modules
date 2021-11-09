#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	name = "lambdaFrag";
	hitpoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap default constructor" << std::endl;
}

FragTrap::FragTrap( std::string name )
	: ClapTrap(name)
{
	hitpoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " created" << std::endl;
}

FragTrap::FragTrap( const FragTrap &oldFragTrap )
	: ClapTrap(oldFragTrap.name)
{
	hitpoints = oldFragTrap.hitpoints;
	energyPoints = oldFragTrap.energyPoints;
	attackDamage = oldFragTrap.attackDamage;
	std::cout << "FragTrap " << name << " created by copy" << std::endl;
}

FragTrap& FragTrap::operator= ( const FragTrap &oldFragTrap )
{
	name = oldFragTrap.name;
	hitpoints = oldFragTrap.hitpoints;
	energyPoints = oldFragTrap.energyPoints;
	attackDamage = oldFragTrap.attackDamage;
	std::cout << "FragTrap " << name << " created with operator=" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destroyed" << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << name << " would really enjoy a high five and a little love" << std::endl;
}
