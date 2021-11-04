#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon& weapon;
public:
	HumanA(std::string newName, Weapon& newWeapon);
	~HumanA();
	void attack(void) const;
};

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

#endif
