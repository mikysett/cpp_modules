#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
private:
	std::string name;
public:
	Zombie( std::string name );
	Zombie( void );
	~Zombie();
	void announce( void );
	void setName( std::string newName );
};

Zombie *zombieHorde( int n, std::string name );

#endif
