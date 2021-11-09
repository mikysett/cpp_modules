#include "ClapTrap.hpp"

// Tests in main taken from dda-silv repo, thanks mate ;)
int	main(void)
{
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

	return (0);
}
