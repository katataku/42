#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	FragTrap("");
}

FragTrap::FragTrap(std::string name)
	: name(name), hitpoints(100), energyPoints(100), attackDamage(30)
{
	std::cout << GREEN << "FragTrap constructor" << RESET << std::endl;
	std::cout << GREEN << "  " << name << " " << hitpoints << " "
			  << energyPoints << " " << attackDamage << RESET << std::endl;
}
FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap destructor" << RESET << std::endl;
}

void FragTrap::attack(std::string const &target)
{
	std::cout << "FragTrap " << name << " attack " << target << ", causing "
			  << attackDamage << " points of damage!" << std::endl;
}
void FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FragTrap " << name << " take damage " << amount
			  << " points of damege!" << std::endl;
}
void FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "FragTrap " << name << " be repaired " << amount
			  << " points of damege!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap HighFive Guys." << std::endl;
}