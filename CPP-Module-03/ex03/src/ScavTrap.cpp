#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	setName("No name");
	setHitpoints(defaultHitpoints);
	setEnergyPoints(defaultEnergyPoints);
	setAttackDamage(defaultAttackDamage);
	std::cout << GREEN << "ScavTrap constructor" << RESET << std::endl;
	std::cout << GREEN << "  " << getName() << " " << getHitpoints() << " "
			  << getEnergyPoints() << " " << getAttackDamage() << RESET
			  << std::endl;
}

ScavTrap::ScavTrap(std::string n)
{
	setName(n);
	setHitpoints(defaultHitpoints);
	setEnergyPoints(defaultEnergyPoints);
	setAttackDamage(defaultAttackDamage);
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
	setName(f.getName());
	setHitpoints(f.getHitpoints());
	setEnergyPoints(f.getEnergyPoints());
	setAttackDamage(f.getAttackDamage());

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