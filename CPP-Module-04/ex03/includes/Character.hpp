#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"
#include "escape_sequence.hpp"
#include <iostream>
#include <string>

class Character : public ICharacter
{
  public:
	Character();
	~Character()
	{
	}

	Character(const std::string &f);

	std::string const &getName() const;
	void			   equip(AMateria *m);
	void			   unequip(int idx);
	void			   use(int idx, Character &target);
};

#endif
