#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
	: name("lambaTrap")
	, hitpoints(10)
	, energyPoints(10)
	, attackDamage(0)
{
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap( std::string name )
	: name(name)
	, hitpoints(10)
	, energyPoints(10)
	, attackDamage(0)
{
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &oldClapTrap )
	: name(oldClapTrap.name)
	, hitpoints(oldClapTrap.hitpoints)
	, energyPoints(oldClapTrap.energyPoints)
	, attackDamage(oldClapTrap.attackDamage)
{
	std::cout << "ClapTrap " << name << " created by copy" << std::endl;
}

ClapTrap& ClapTrap::operator= ( const ClapTrap &oldClapTrap )
{
	name = oldClapTrap.name;
	hitpoints = oldClapTrap.hitpoints;
	energyPoints = oldClapTrap.energyPoints;
	attackDamage = oldClapTrap.attackDamage;
	std::cout << "ClapTrap " << name << " copied with operator=" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

void ClapTrap::attack( std::string const &target )
{
	std::cout << "ClapTrap " << name << " attack " << target
		<< ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount )
{
	hitpoints -= amount;
	std::cout << "ClapTrap " << name << " is attacted, taking "
		<< amount << " points of damage! ";
	if (hitpoints > 0)
		std::cout << hitpoints << " hitpoints remaining." << std::endl;
	else
	{
		hitpoints = 0;
		std::cout << "The trap died!" << std::endl;
	}
}

void ClapTrap::beRepaired( unsigned int amount )
{
	hitpoints += amount;
	std::cout << "ClapTrap " << name << " is repared, healing "
		<< amount << " points of health!"
		<< "Now he has " << hitpoints << " hitpoints" << std::endl;
}
