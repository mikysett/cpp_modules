#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# define MATERIA_SIZE 4
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* materia[MATERIA_SIZE];
public:
	MateriaSource();
	MateriaSource( const MateriaSource &oldMateriaSource );
	MateriaSource& operator= ( const MateriaSource &oldMateriaSource );
	~MateriaSource();

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

};

#endif
