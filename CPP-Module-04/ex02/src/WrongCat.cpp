#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << GREEN << "WrongCat constructor" << RESET << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat destructor" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	*this = other;
	std::cout << GREEN << "WrongCat constructor" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	type			   = other.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout  << "Wrong Nya nya" << RESET << std::endl;
}