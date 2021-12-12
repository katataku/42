#include "Zombie.hpp"

int main(void)
{
	Zombie	*zombie =  newZombie("new Zombie");
	zombie->announce();
	delete zombie;
	randomChump("random Zombie");
	return (0);
}
