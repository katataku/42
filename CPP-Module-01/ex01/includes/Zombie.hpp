#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include "escape_sequence.hpp"
#include <string>

class	Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
		void	setName(std::string name);
	private:
		std::string	_name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
