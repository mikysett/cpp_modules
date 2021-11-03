#include "Zombie.hpp"

int main( void )
{
	Zombie *horde;
	const int nbZombies = 10;

	horde = zombieHorde(nbZombies, "Joseph");
	for (int i = 0; i < nbZombies; i++ )
		horde[i].announce();
	delete[] horde;
	return (0);
}