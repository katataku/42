#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();

	std::cout << GREEN << "Cat constructor" << RESET << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << RED << "Cat destructor" << RESET << std::endl;
}

Cat::Cat(Cat const &f)
{
	brain = new Brain();
	*this = f;
	std::cout << GREEN << "Cat constructor" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &f)
{
	delete brain;
	this->brain = new Brain();
	*(this->brain) = *(f.brain);
	type   = f.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout  << "Nya nya" << RESET << std::endl;
}

void Cat::getBrainIdea(int i) const
{
	std::cout << this->brain->getBrainIdea(i) << RESET << std::endl;
}

void Cat::setBrainIdea(int i, std::string idea)
{
	brain->setBrainIdea(i, idea);
}
