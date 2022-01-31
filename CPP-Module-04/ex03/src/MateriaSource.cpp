#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
}

MateriaSource::MateriaSource(MateriaSource &f)
{
	for (int i = 0; i < 4; i++)
	{
		if (f.inventory[i] != NULL)
			inventory[i] = f.inventory[i]->clone();
	}
}
MateriaSource &MateriaSource::operator=(const MateriaSource &f)
{
	for (int i = 0; i < 4; i++)
	{
		if (f.inventory[i] != NULL)
			inventory[i] = f.inventory[i];
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			break;
		}
	}
}
AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
			continue;

		if (inventory[i]->getType() == type)
		{
			return inventory[i]->clone();
		}
	}
	return NULL;
}