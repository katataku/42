#include "Character.hpp"

Character::Character() : name("no name")
{
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

Character::~Character()
{
}

Character::Character(Character &f)
{
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = f.inventory[i]->clone();
	}
}

Character::Character(const std::string &f) : name(f)
{
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

Character &Character::operator=(const Character &f)
{
	for (int i = 0; i < 4; i++)
	{
		delete inventory[i];
		inventory[i] = f.inventory[i]->clone();
	}
	return *this;
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
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

void Character::unequip(int idx)
{
	if (0 <= idx && idx <= 3)
		inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (0 <= idx && idx <= 3)
	{
		if (inventory[idx] != NULL)
			inventory[idx]->use(target);
	}
}