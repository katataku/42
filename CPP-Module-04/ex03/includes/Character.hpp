#ifndef CHARACTER
#define CHARACTER

#include "ICharacter.hpp"
#include "AMateria.hpp"

#include "escape_sequence.hpp"
#include <iostream>
#include <string>

class Character : public ICharacter
{
  private:
	std::string const name;
	AMateria *inventory[4];

  public:
	Character();
	~Character();

	Character(const std::string &f);
	Character(Character &f);
	Character &operator=(const Character &);

	std::string const &getName() const;
	void			   equip(AMateria *m);
	void			   unequip(int idx);
	void			   use(int idx, ICharacter &target);
};

#endif
