#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap A("a");
	ScavTrap B;
	ScavTrap C(A);

	A.attack("b");
	B.takeDamage(10);
	A.beRepaired(3);
	A.guardGate();
}