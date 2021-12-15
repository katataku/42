#include "HumanA.hpp"


HumanA::HumanA(std::string n,Weapon& w) : _name(n), weapon(w)
{

}

void	HumanA::attack()
{
	std::cout 	<< _name
				<< " attacks with his " 
				<< weapon.getType()
				<<std::endl;
}