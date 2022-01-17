#ifndef Ice_H
#define Ice_H

#include "escape_sequence.hpp"
#include <AMateria.hpp>
#include <iostream>
#include <string>
class Ice: public AMateria
{

  public:
	Ice();
	~Ice();
	Ice(const Ice &);
	Ice &operator=(const Ice &);

	Ice(std::string const &type);

	std::string const &getType() const; // Returns the materia type
	AMateria			 *clone() const;
	void			   use(ICharacter &target);
};

#endif
