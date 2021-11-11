#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# define MATERIA_SIZE 4
# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string name;
	AMateria* materia[MATERIA_SIZE];
public:
	Character();
	Character( std::string name );
	Character( const Character &oldCharacter );
	Character& operator= ( const Character &oldCharacter );
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif
