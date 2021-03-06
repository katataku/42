#ifndef FRAGTRAP
#define FRAGTRAP

#include "ClapTrap.hpp"
#include "escape_sequence.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap
{
  public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap &);

	FragTrap &operator=(const FragTrap &);

	void highFivesGuys(void);
};

#endif
