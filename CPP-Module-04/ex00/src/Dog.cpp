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

Dog::Dog(const Dog &f)
{
	*this = f;
	std::cout << GREEN << "Dog constructor" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &f)
{
	type			   = f.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout  << "Bow wow" << RESET << std::endl;
}