#include "Zombie.hpp"

int main( void )
{
	Zombie adam = Zombie("Adam");
	Zombie *bram = newZombie("bram");

	adam.announce();
	randomChump("Luis");
	bram->announce();
	delete bram;
	return (0);
}