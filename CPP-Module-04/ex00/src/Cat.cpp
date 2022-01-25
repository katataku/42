#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << GREEN << "Cat constructor" << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << "Cat destructor" << RESET << std::endl;
}

Cat::Cat(const Cat &other)
{
	*this = other;
	std::cout << GREEN << "Cat constructor" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	type			   = other.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout  << "Nya nya" << RESET << std::endl;
}