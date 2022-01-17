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

WrongCat::WrongCat(const WrongCat &f)
{
	*this = f;
	std::cout << GREEN << "WrongCat constructor" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &f)
{
	type			   = f.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout  << "Wrong Nya nya" << RESET << std::endl;
}