# include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MATERIA_SIZE; i++)
		materia[i] = 0;
}

MateriaSource::MateriaSource( const MateriaSource &oldMateriaSource )
{
	for (int i = 0; i < MATERIA_SIZE; i++)
	{
		if (oldMateriaSource.materia[i] != 0)
		{
			materia[i] = oldMateriaSource.materia[i]->clone();
			delete oldMateriaSource.materia[i];
		}
		else
			materia[i] = 0;
	}
}

MateriaSource& MateriaSource::operator= ( const MateriaSource &oldMateriaSource )
{
	for (int i = 0; i < MATERIA_SIZE; i++)
	{
		if (oldMateriaSource.materia[i] != 0)
		{
			materia[i] = oldMateriaSource.materia[i]->clone();
			delete oldMateriaSource.materia[i];
		}
		else
			materia[i] = 0;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MATERIA_SIZE; i++)
		if (materia[i] != 0)
			delete materia[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < MATERIA_SIZE; i++)
		if (materia[i] == 0)
		{
			materia[i] = m;
			return ;
		}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MATERIA_SIZE; i++)
		if (materia[i] != 0 && materia[i]->getType() == type)
			return (materia[i]->clone());
	return (0);
}
