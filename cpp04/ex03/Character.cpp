#include "Character.hpp"

Character::Character()
	: name("lambda guy")
{
	for (int i = 0; i < MATERIA_SIZE; i++)
		materia[i] = nullptr;
}

Character::Character(std::string name)
	: name(name)
{
	for (int i = 0; i < MATERIA_SIZE; i++)
		materia[i] = nullptr;
}

Character::Character( const Character &oldCharacter )
	: name(oldCharacter.name)
{
	for (int i = 0; i < MATERIA_SIZE; i++)
	{
		if (oldCharacter.materia[i] != nullptr)
		{
			materia[i] = oldCharacter.materia[i]->clone();
			delete oldCharacter.materia[i];
		}
		else
			materia[i] = nullptr;
	}
}

Character& Character::operator= ( const Character &oldCharacter )
{
	name = oldCharacter.name;
	for (int i = 0; i < MATERIA_SIZE; i++)
	{
		if (oldCharacter.materia[i] != nullptr)
		{
			materia[i] = oldCharacter.materia[i]->clone();
			delete oldCharacter.materia[i];
		}
		else
			materia[i] = nullptr;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < MATERIA_SIZE; i++)
		if (materia[i] != nullptr)
			delete materia[i];
}

std::string const & Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < MATERIA_SIZE; i++)
		if (materia[i] == nullptr)
			materia[i] = m->clone();
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < MATERIA_SIZE
		&& materia[idx] != nullptr)
		materia[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < MATERIA_SIZE
		&& materia[idx] != nullptr)
		materia[idx]->use(target);
}
