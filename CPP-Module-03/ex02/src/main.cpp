#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
int main(void)
{
	ClapTrap A("a"), B("b");
	A.attack("b");
	B.takeDamage(10);
	A.beRepaired(3);

	std::cout << std::endl;
	std::cout << std::endl;

	ScavTrap C("c"), D("d");
	C.attack("c");
	D.takeDamage(10);
	C.beRepaired(3);
	C.guardGate();

	std::cout << std::endl;
	std::cout << std::endl;

	FragTrap E("e"), F("f");
	E.attack("e");
	F.takeDamage(10);
	E.beRepaired(3);
	E.highFivesGuys();
}