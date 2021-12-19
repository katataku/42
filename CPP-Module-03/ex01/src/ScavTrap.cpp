#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	ScavTrap("");
}

ScavTrap::ScavTrap(std::string name)
	: name(name), hitpoints(100), energyPoints(50), attackDamage(20)
{
	std::cout << GREEN << "ScavTrap constructor" << RESET << std::endl;
	std::cout << GREEN << "  " << name << " " << hitpoints << " "
			  << energyPoints << " " << attackDamage << RESET << std::endl;
}
ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap destructor" << RESET << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap " << name << " attack " << target << ", causing "
			  << attackDamage << " points of damage!" << std::endl;
}
void ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap " << name << " take damage " << amount
			  << " points of damege!" << std::endl;
}
void ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "ScavTrap " << name << " be repaired " << amount
			  << " points of damege!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap entered in the Gate keeper mode." << std::endl;
}