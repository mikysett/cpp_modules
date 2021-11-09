#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: name("lambdaDiamond")
{
	ClapTrap::name = name + "_clap_name";
	hitpoints = FragTrap::hitpoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap default constructor" << std::endl;
}

DiamondTrap::DiamondTrap( std::string newName )
	: name(newName)
{
	ClapTrap::name = name + "_clap_name";
	hitpoints = FragTrap::hitpoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap " << name << " created" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &oldDiamondTrap )
	: name(oldDiamondTrap.name)
{
	ClapTrap::name = name + "_clap_name";
	hitpoints = oldDiamondTrap.hitpoints;
	energyPoints = oldDiamondTrap.energyPoints;
	attackDamage = oldDiamondTrap.attackDamage;
	std::cout << "DiamondTrap " << name << " created by copy" << std::endl;
}

DiamondTrap& DiamondTrap::operator= ( const DiamondTrap &oldDiamondTrap )
{
	name = oldDiamondTrap.name;
	ClapTrap::name = name + "_clap_name";
	hitpoints = oldDiamondTrap.hitpoints;
	energyPoints = oldDiamondTrap.energyPoints;
	attackDamage = oldDiamondTrap.attackDamage;
	std::cout << "DiamondTrap " << name << " created with operator=" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " destroyed" << std::endl;
}

void DiamondTrap::whoAmI( void )
{
	std::cout << "WHOAMI  --> Diamond name: " << name << ", Clap name: " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack( std::string const &target )
{
	std::cout << "ATTACK FROM SCAVTRAP: ";
	this->ScavTrap::attack( target );
}
