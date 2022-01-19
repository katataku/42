#ifndef IMATERIASOURCE_H
#define IMATERIASOURCE_H

#include "AMateria.hpp"
#include "escape_sequence.hpp"
#include <iostream>
#include <string>

class IMateriaSource
{
  public:
	virtual ~IMateriaSource()
	{
	}
	virtual void	  learnMateria(AMateria *)				 = 0;
	virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif
