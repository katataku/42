#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "escape_sequence.hpp"
#include <iostream>
#include <string>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
public:
~MateriaSource() {}
void learnMateria(AMateria*);
AMateria* createMateria(std::string const & type);
};

#endif
