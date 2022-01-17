#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	setName("No name");
	setHitpoints(defaultHitpoints);
	setEnergyPoints(defaultEnergyPoints);
	setAttackDamage(defaultAttackDamage);
	std::cout << GREEN << "FragTrap constructor" << RESET << std::endl;
	std::cout << GREEN << "  " << getName() << " " << getHitpoints() << " "
			  << getEnergyPoints() << " " << getAttackDamage() << RESET
			  << std::endl;
}

FragTrap::FragTrap(std::string n)
{
	setName(n);
	setHitpoints(defaultHitpoints);
	setEnergyPoints(defaultEnergyPoints);
	setAttackDamage(defaultAttackDamage);
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
	setName(f.getName());
	setHitpoints(f.getHitpoints());
	setEnergyPoints(f.getEnergyPoints());
	setAttackDamage(f.getAttackDamage());
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << getName()
			  << " a positive high fives request " << std::endl;
}