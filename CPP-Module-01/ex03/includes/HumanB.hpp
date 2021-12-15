#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include "escape_sequence.hpp"
#include <iostream>
#include <string>

class HumanB
{
  private:
	std::string _name;
	Weapon	   *_weapon;

  public:
	HumanB(std::string n);
	HumanB(std::string name, Weapon *weapon);
	void attack();
	void setWeapon(Weapon& weapon);
};

#endif
