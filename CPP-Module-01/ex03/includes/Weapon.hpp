#ifndef WEAPON_HPP
#define WEAPON_HPP
#include "escape_sequence.hpp"
#include <iostream>
#include <string>

class Weapon
{
  private:
	std::string _type;

  public:
	Weapon();
	Weapon(std::string type);
	~Weapon();
	const std::string &getType();
	void			   setType(std::string type);
};

#endif
