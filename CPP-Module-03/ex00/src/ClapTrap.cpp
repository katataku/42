#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	ClapTrap("");
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hitpoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << GREEN << "ClapTrap constructor" << RESET << std::endl;
	std::cout << GREEN << "  " << name << " " << hitpoints << " "
			  << energyPoints << " " << attackDamage << RESET << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap destructor" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &)
{
}

ClapTrap &ClapTrap::operator=(ClapTrap const &f)
{
	this->hitpoints	   = f.hitpoints;
	this->energyPoints = f.energyPoints;
	this->attackDamage = f.attackDamage;
	return *this;
}
void ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << name << " attack " << target << ", causing "
			  << attackDamage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " take damage " << amount
			  << " points of damege!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " be repaired " << amount
			  << " points of damege!" << std::endl;
}