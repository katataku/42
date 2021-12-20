#ifndef SCAVTRAP
#define SCAVTRAP

#include "ClapTrap.hpp"
#include "escape_sequence.hpp"
#include <iostream>
#include <string>

class ScavTrap : public ClapTrap
{
  private:
	std::string	 name;
	unsigned int hitpoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

  public:
  	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();

	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void guardGate(); 
};

#endif
