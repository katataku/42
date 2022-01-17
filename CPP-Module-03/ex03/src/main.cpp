#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap A("a");
	DiamondTrap B;
	DiamondTrap C(A);

	A.attack("b");
	B.takeDamage(10);
	A.beRepaired(3);
	A.whoAmI();
}