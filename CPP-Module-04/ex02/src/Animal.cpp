#include "Animal.hpp"

Animal::Animal()
{
	std::cout << GREEN << "Animal constructor" << RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << RED << "Animal destructor" << RESET << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << GREEN << "Animal constructor" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	type			   = other.type;
	return *this;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout <<"ani mal" << RESET << std::endl;
}