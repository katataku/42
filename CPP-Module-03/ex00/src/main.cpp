#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap A("a");
	ClapTrap B;
	ClapTrap C(A);

	A.attack("b");
	B.takeDamage(10);
	A.beRepaired(3);
}