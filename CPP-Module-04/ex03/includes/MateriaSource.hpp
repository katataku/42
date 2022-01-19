#ifndef MATERIASOURCE
#define MATERIASOURCE

#include "IMateriaSource.hpp"
#include "escape_sequence.hpp"
#include <iostream>
#include <string>

class MateriaSource : public IMateriaSource
{
  private:
	AMateria *inventory[4];

  public:
	MateriaSource();
	~MateriaSource()
	{
	}
	MateriaSource(MateriaSource &f);
	MateriaSource &operator=(const MateriaSource &);

	void	  learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);
};

#endif
