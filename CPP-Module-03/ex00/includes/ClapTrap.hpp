#ifndef CLAPTRAP
#define CLAPTRAP

#include "escape_sequence.hpp"
#include <iostream>
#include <string>
#define EIGHT_BIT 256
class ClapTrap
{
  private:
	std::string	 name;
	unsigned int hitpoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

  public:
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &);

	ClapTrap &operator=(const ClapTrap &);

	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
