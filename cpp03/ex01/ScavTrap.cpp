#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	name = "lambdaScav";
	hitpoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap( std::string name )
	: ClapTrap(name)
{
	hitpoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " created" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &oldScavTrap )
	: ClapTrap(oldScavTrap.name)
{
	hitpoints = oldScavTrap.hitpoints;
	energyPoints = oldScavTrap.energyPoints;
	attackDamage = oldScavTrap.attackDamage;
	std::cout << "ScavTrap " << name << " created by copy" << std::endl;
}

ScavTrap& ScavTrap::operator= ( const ScavTrap &oldScavTrap )
{
	name = oldScavTrap.name;
	hitpoints = oldScavTrap.hitpoints;
	energyPoints = oldScavTrap.energyPoints;
	attackDamage = oldScavTrap.attackDamage;
	std::cout << "ScavTrap " << name << " created with operator=" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destroyed" << std::endl;
}

void ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << name << " have enterred in Gate keeper mode" << std::endl;
}

void ScavTrap::attack( std::string const &target )
{
	if (hitpoints > 0 && energyPoints > 0) {
		std::cout << "ScavTrap " << name << " attack " << target
			<< ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "ScavTrap " << name << " can't attack!";
	}
}
