#include "Zombie.hpp"
#include "escape_sequence.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
}

Zombie::~Zombie()
{
	std::cout	<< RED
				<< _name
				<< " is purified"
				<< RESET
				<< std::endl;
}

void	Zombie::announce()
{
	std::cout	<< GREEN
				<< "<" << _name << ">"
				<< " BraiiiiiiinnnzzzZ..."
				<< RESET
				<< std::endl;
}
