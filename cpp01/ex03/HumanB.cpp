#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: name(name)
	, weapon(0)
{}

HumanB::~HumanB()
{}

void HumanB::attack(void) const
{
	if (weapon != 0)
		std::cout << name << " attacks with his " << weapon->getType() << std::endl;
	else
		std::cout << name << " attacks with his bare hands" << std::endl;
}

void HumanB::setWeapon(Weapon& newWeapon)
{
	weapon = &newWeapon;
}
