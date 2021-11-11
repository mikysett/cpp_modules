# include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MATERIA_SIZE; i++)
		materia[i] = nullptr;
}

MateriaSource::MateriaSource( const MateriaSource &oldMateriaSource )
{
	for (int i = 0; i < MATERIA_SIZE; i++)
	{
		if (oldMateriaSource.materia[i] != nullptr)
		{
			materia[i] = oldMateriaSource.materia[i]->clone();
			delete oldMateriaSource.materia[i];
		}
		else
			materia[i] = nullptr;
	}
}

MateriaSource& MateriaSource::operator= ( const MateriaSource &oldMateriaSource )
{
	for (int i = 0; i < MATERIA_SIZE; i++)
	{
		if (oldMateriaSource.materia[i] != nullptr)
		{
			materia[i] = oldMateriaSource.materia[i]->clone();
			delete oldMateriaSource.materia[i];
		}
		else
			materia[i] = nullptr;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MATERIA_SIZE; i++)
		if (materia[i] != nullptr)
			delete materia[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < MATERIA_SIZE; i++)
		if (materia[i] == nullptr)
			materia[i] = m->clone();
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MATERIA_SIZE; i++)
		if (materia[i] != nullptr
			&& materia[i]->getType() == type)
			return (materia[i]->clone());
	return (0);
}
