#include "ScavTrap.hpp"

// Tests in main taken from dda-silv repo, thanks mate ;)
static void test_claptrap(void) {
	ClapTrap bot1;
	ClapTrap bot2("Robocop");
	ClapTrap bot3("Model 101 (aka The Terminator)");
	ClapTrap bot4("Alexa");

	bot1.attack("Robocop");
	bot2.takeDamage(2);

	bot3.attack("Alexa");
	bot4.takeDamage(11);

	bot3.attack("Robocop");
	bot2.takeDamage(5);
	bot2.beRepaired(4);
}

static void test_scravtrap(void) {
	ScavTrap bot1;
	ScavTrap bot2("Siri");
	ScavTrap bot3("Google");

	bot1.attack("Siri");
	bot2.takeDamage(42);

	bot3.attack("Siri");
	bot2.takeDamage(55);
	bot2.guardGate();
	bot2.beRepaired(40);
}

int main(void) {
	test_claptrap();
	std::cout << std::endl;
	test_scravtrap();

	return 0;
}
