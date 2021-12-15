#include "HumanB.hpp"

HumanB::HumanB(std::string n) : _name(n), _weapon(NULL)
{
}

HumanB::HumanB(std::string n, Weapon *w) : _name(n), _weapon(w)
{
}

void HumanB::attack()
{
	if (_weapon != NULL)
	{
		std::cout << _name << " attacks with his " << _weapon->getType()
				  << std::endl;
	} else
	{
		std::cout << _name << " attacks without weapon" << std::endl;
	}
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}