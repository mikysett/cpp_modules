#include "Character.hpp"

Character::Character()
	: name("lambda guy")
{
	for (int i = 0; i < MATERIA_SIZE; i++)
		materia[i] = 0;
}

Character::Character(std::string name)
	: name(name)
{
	for (int i = 0; i < MATERIA_SIZE; i++)
		materia[i] = 0;
}

Character::Character( const Character &oldCharacter )
	: name(oldCharacter.name)
{
	for (int i = 0; i < MATERIA_SIZE; i++)
	{
		if (oldCharacter.materia[i] != 0)
			materia[i] = oldCharacter.materia[i]->clone();
		else
			materia[i] = 0;
	}
}

Character& Character::operator= ( const Character &oldCharacter )
{
	name = oldCharacter.name;
	for (int i = 0; i < MATERIA_SIZE; i++)
		if (materia[i] != 0)
			delete materia[i];
	for (int i = 0; i < MATERIA_SIZE; i++)
	{
		if (oldCharacter.materia[i] != 0)
			materia[i] = oldCharacter.materia[i]->clone();
		else
			materia[i] = 0;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < MATERIA_SIZE; i++)
		if (materia[i] != 0)
			delete materia[i];
}

std::string const & Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < MATERIA_SIZE; i++)
		if (materia[i] == 0)
		{
			materia[i] = m;
			return ;
		}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < MATERIA_SIZE
		&& materia[idx] != 0)
		materia[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < MATERIA_SIZE
		&& materia[idx] != 0)
		materia[idx]->use(target);
}
