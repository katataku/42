#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	name = "noname";
	setName("noname_clap_name");
	setHitpoints(FragTrap::defaultHitpoints);
	setEnergyPoints(ScavTrap::defaultEnergyPoints);
	setAttackDamage(FragTrap::defaultAttackDamage);
	std::cout << GREEN << "DiamondTrap constructor" << RESET << std::endl;
	std::cout << GREEN << "  " << getName() << " " << getHitpoints() << " "
			  << getEnergyPoints() << " " << getAttackDamage() << RESET
			  << std::endl;
}

DiamondTrap::DiamondTrap(std::string n)
{
	name = n;
	setName(n + "_clap_name");
	setHitpoints(FragTrap::defaultHitpoints);
	setEnergyPoints(ScavTrap::defaultEnergyPoints);
	setAttackDamage(FragTrap::defaultAttackDamage);
	std::cout << GREEN << "DiamondTrap constructor" << RESET << std::endl;
	std::cout << GREEN << "  " << getName() << " " << getHitpoints() << " "
			  << getEnergyPoints() << " " << getAttackDamage() << RESET
			  << std::endl;
}
DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap destructor" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &f)
{
	*this = f;
	std::cout << GREEN << "DiamondTrap constructor" << RESET << std::endl;
	std::cout << GREEN << "  " << getName() << " " << getHitpoints() << " "
			  << getEnergyPoints() << " " << getAttackDamage() << RESET
			  << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &f)
{
	setName(f.getName());
	setHitpoints(f.getHitpoints());
	setEnergyPoints(f.getEnergyPoints());
	setAttackDamage(f.getAttackDamage());
	return *this;
}

void DiamondTrap::attack(std::string const &target)
{
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
		std::cout << "DiamondTrap it's name:" << name << std::endl;
		std::cout << "DiamondTrap ClapTrap name:" << getName() << std::endl;

}