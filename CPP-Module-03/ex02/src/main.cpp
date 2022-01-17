#include "FragTrap.hpp"

int main(void)
{
	FragTrap A("a");
	FragTrap B;
	FragTrap C(A);

	A.attack("b");
	B.takeDamage(10);
	A.beRepaired(3);
	A.highFivesGuys();
}