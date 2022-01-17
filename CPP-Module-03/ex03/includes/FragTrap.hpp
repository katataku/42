#ifndef FRAGTRAP
#define FRAGTRAP

#include "ClapTrap.hpp"
#include "escape_sequence.hpp"
#include <iostream>
#include <string>

class FragTrap : virtual public ClapTrap
{
  public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap &);

	FragTrap &operator=(const FragTrap &);

	void highFivesGuys(void);

	protected:
	static const unsigned int defaultHitpoints = 100;
	static const unsigned int defaultEnergyPoints = 100;
	static const unsigned int defaultAttackDamage = 30;
};

#endif
