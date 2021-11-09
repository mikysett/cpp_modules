// Tests in main taken from dda-silv repo, thanks mate ;)
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

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

static void test_fragtrap(void) {
	FragTrap bot1;
	FragTrap bot2("J.A.R.V.I.S.");
	FragTrap bot3("R2-D2");

	bot1.attack("R2-D2");
	bot2.takeDamage(42);

	bot3.attack("J.A.R.V.I.S.");
	bot2.takeDamage(55);
	bot3.highFivesGuys();
	bot3.beRepaired(40);
}

int main(void) {
	test_claptrap();
	std::cout << std::endl;
	test_fragtrap();

	return 0;
}
