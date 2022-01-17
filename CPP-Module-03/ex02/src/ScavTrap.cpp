#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	name		 = "No name";
	hitpoints	 = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << GREEN << "ScavTrap constructor" << RESET << std::endl;
	std::cout << GREEN << "  " << getName() << " " << getHitpoints() << " "
			  << getEnergyPoints() << " " << getAttackDamage() << RESET
			  << std::endl;
}

ScavTrap::ScavTrap(std::string n)
{
	name		 = n;
	hitpoints	 = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << GREEN << "ScavTrap constructor" << RESET << std::endl;
	std::cout << GREEN << "  " << getName() << " " << getHitpoints() << " "
			  << getEnergyPoints() << " " << getAttackDamage() << RESET
			  << std::endl;
}
ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap destructor" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &f)
{
	*this = f;
	std::cout << GREEN << "ScavTrap constructor" << RESET << std::endl;
	std::cout << GREEN << "  " << getName() << " " << getHitpoints() << " "
			  << getEnergyPoints() << " " << getAttackDamage() << RESET
			  << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &f)
{
	name			   = f.getName();
	hitpoints		   = f.getHitpoints();
	this->energyPoints = f.getEnergyPoints();
	this->attackDamage = f.getAttackDamage();
	return *this;
}

void ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap " << getName() << " attack " << target
			  << ", causing " << getAttackDamage() << " points of damage!"
			  << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName()
			  << " have enterred in Gate keeper mode " << std::endl;
}