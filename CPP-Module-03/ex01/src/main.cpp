#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main(void)
{
	ClapTrap A("a"),B("b");
	A.attack("b");
	B.takeDamage(10);
	A.beRepaired(3);

	std::cout << std::endl;
	std::cout << std::endl;

	ScavTrap C("c"),D("d");
	C.attack("c");
	D.takeDamage(10);
	C.beRepaired(3);
}