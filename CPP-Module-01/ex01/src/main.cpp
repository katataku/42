#include "Zombie.hpp"

int main(void)
{
	int		N = 10;
	Zombie	*zombies = zombieHorde(N, "takkatao");
	for (int i = 0; i < N; i++)
	{
		std::cout << i << " : ";
		zombies[i].announce();
	}
	delete [] zombies;
	return (0);
}
