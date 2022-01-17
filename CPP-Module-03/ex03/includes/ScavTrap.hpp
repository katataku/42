#ifndef SCAVTRAP
#define SCAVTRAP

#include "ClapTrap.hpp"
#include "escape_sequence.hpp"
#include <iostream>
#include <string>
class ScavTrap : virtual public ClapTrap
{
  public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap &);

	ScavTrap &operator=(const ScavTrap &);

	void attack(std::string const &target);
	void guardGate();

  protected:
	static const unsigned int defaultHitpoints	  = 100;
	static const unsigned int defaultEnergyPoints = 50;
	static const unsigned int defaultAttackDamage = 20;
};

#endif
