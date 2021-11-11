#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure( const Cure &oldCure );
	Cure& operator= ( const Cure &oldCure );
	~Cure();
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
