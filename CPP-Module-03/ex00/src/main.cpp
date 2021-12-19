#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap A("a"),B("b");

	A.attack("b");
	B.takeDamage(10);
	A.beRepaired(3);
}