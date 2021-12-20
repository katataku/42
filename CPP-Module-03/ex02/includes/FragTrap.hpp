#ifndef FRAGTRAP
#define FRAGTRAP

#include "ClapTrap.hpp"
#include "escape_sequence.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap
{
  private:
	std::string	 name;
	unsigned int hitpoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

  public:
  	FragTrap();
	FragTrap(std::string name);
	~FragTrap();

	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void highFivesGuys(void); 
};

#endif
