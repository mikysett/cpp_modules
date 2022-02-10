#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon& newWeapon)
	: name(newName)
	, weapon(newWeapon)
{}

HumanA::~HumanA()
{}

void HumanA::attack(void) const
{
	std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}
