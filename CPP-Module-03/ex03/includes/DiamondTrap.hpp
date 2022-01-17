#ifndef DIAMONDTRAP
#define DIAMONDTRAP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "escape_sequence.hpp"
#include <iostream>
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
 private:
	std::string	 name;

  public:
	DiamondTrap();
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap &);

	DiamondTrap &operator=(const DiamondTrap &);

	void attack(std::string const &target);

	void whoAmI();
};

#endif
