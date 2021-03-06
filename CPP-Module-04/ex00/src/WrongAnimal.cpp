#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: type("Dog")
{
	std::cout << GREEN << "WrongAnimal constructor" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string t)
	: type(t)
{
	std::cout << GREEN << "WrongAnimal constructor" << RESET << std::endl;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal destructor" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
	std::cout << GREEN << "WrongAnimal constructor" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	type			   = other.type;
	return *this;
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout <<"Wrong Ani mal" << RESET << std::endl;
}