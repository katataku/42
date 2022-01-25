#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << GREEN << "Dog constructor" << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << RED << "Dog destructor" << RESET << std::endl;
}

Dog::Dog(const Dog &other)
{
	*this = other;
	std::cout << GREEN << "Dog constructor" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	type			   = other.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout  << "Bow wow" << RESET << std::endl;
}