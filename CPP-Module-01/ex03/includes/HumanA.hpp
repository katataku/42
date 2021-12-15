#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include "escape_sequence.hpp"
#include <iostream>
#include <string>

class HumanA
{
  private:
	std::string _name;
	Weapon	   &weapon;

  public:
	HumanA(std::string name, Weapon &weapon);
	void attack();
};

#endif
