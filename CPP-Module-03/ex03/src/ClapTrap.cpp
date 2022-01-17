#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name("No name"), hitpoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << GREEN << "ClapTrap constructor" << RESET << std::endl;
	std::cout << GREEN << "  " << getName() << " " << getHitpoints() << " "
			  << getEnergyPoints() << " " << getAttackDamage() << RESET
			  << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hitpoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << GREEN << "ClapTrap constructor" << RESET << std::endl;
	std::cout << GREEN << "  " << getName() << " " << getHitpoints() << " "
			  << getEnergyPoints() << " " << getAttackDamage() << RESET
			  << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap destructor" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &f)
{
	*this = f;
	std::cout << GREEN << "ClapTrap constructor" << RESET << std::endl;
	std::cout << GREEN << "  " << getName() << " " << getHitpoints() << " "
			  << getEnergyPoints() << " " << getAttackDamage() << RESET
			  << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &f)
{
	name			   = f.getName();
	hitpoints		   = f.getHitpoints();
	this->energyPoints = f.getEnergyPoints();
	this->attackDamage = f.getAttackDamage();
	return *this;
}
void ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << getName() << " attack " << target
			  << ", causing " << getAttackDamage() << " points of damage!"
			  << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << getName() << " take damage " << amount
			  << " points of damege!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << getName() << " be repaired " << amount
			  << " points of damege!" << std::endl;
}

std::string ClapTrap::getName() const
{
	return name;
}

void ClapTrap::setName(std::string n)
{
	name = n;
}

unsigned int ClapTrap::getHitpoints() const
{
	return hitpoints;
}
void ClapTrap::setHitpoints(unsigned int h)
{
	hitpoints = h;
}
unsigned int ClapTrap::getEnergyPoints() const
{
	return energyPoints;
}
void ClapTrap::setEnergyPoints(unsigned int h)
{
	energyPoints = h;
}
unsigned int ClapTrap::getAttackDamage() const
{
	return attackDamage;
}
void ClapTrap::setAttackDamage(unsigned int h)
{
	attackDamage = h;
}