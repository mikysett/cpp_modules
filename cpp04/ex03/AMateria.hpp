#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include "ICharacter.hpp"

// Forward declaration of ICharacter to solve mutual dependencies
class ICharacter;

class AMateria
{
protected:
	std::string type;
public:
	AMateria();
	AMateria( std::string const &type );
	AMateria( const AMateria &oldAMateria );
	AMateria& operator= ( const AMateria &oldAMateria );
	~AMateria();

	std::string const& getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
