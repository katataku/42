#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	name		 = "No name";
	hitpoints	 = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << GREEN << "FragTrap constructor" << RESET << std::endl;
	std::cout << GREEN << "  " << getName() << " " << getHitpoints() << " "
			  << getEnergyPoints() << " " << getAttackDamage() << RESET
			  << std::endl;
}

FragTrap::FragTrap(std::string n)
{
	name		 = n;
	hitpoints	 = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << GREEN << "FragTrap constructor" << RESET << std::endl;
	std::cout << GREEN << "  " << getName() << " " << getHitpoints() << " "
			  << getEnergyPoints() << " " << getAttackDamage() << RESET
			  << std::endl;
}
FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap destructor" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &f)
{
	*this = f;
	std::cout << GREEN << "FragTrap constructor" << RESET << std::endl;
	std::cout << GREEN << "  " << getName() << " " << getHitpoints() << " "
			  << getEnergyPoints() << " " << getAttackDamage() << RESET
			  << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &f)
{
	name			   = f.getName();
	hitpoints		   = f.getHitpoints();
	this->energyPoints = f.getEnergyPoints();
	this->attackDamage = f.getAttackDamage();
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << getName()
			  << " a positive high fives request " << std::endl;
}