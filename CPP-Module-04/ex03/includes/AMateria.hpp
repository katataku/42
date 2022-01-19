#ifndef AMATERIA_H
#define AMATERIA_H

#include "escape_sequence.hpp"
#include <iostream>
#include <string>
class ICharacter;
class AMateria
{
  protected:
	std::string type;
	
  public:
	virtual ~AMateria();
	AMateria(std::string const &type);
	std::string const &getType() const; // Returns the materia type
	virtual AMateria	 *clone() const = 0;
	virtual void	   use(ICharacter &target);
};

#endif
