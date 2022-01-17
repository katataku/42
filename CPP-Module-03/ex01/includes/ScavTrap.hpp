#ifndef SCAVTRAP
#define SCAVTRAP

#include "escape_sequence.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>
class ScavTrap : public ClapTrap
{
  public:
  	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap &);

	ScavTrap &operator=(const ScavTrap &);

	void attack(std::string const &target);
	void guardGate(); 
};

#endif
