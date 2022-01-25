#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();

	std::cout << GREEN << "Dog constructor" << RESET << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << RED << "Dog destructor" << RESET << std::endl;
}

Dog::Dog(Dog const &f)
{
	brain = new Brain();
	*this = f;
	std::cout << GREEN << "Dog constructor" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &f)
{

	this->brain = new Brain();
	*(this->brain) = *(f.brain);
	type   = f.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout  << "Nya nya" << RESET << std::endl;
}

void Dog::getBrainIdea(int i) const
{
	std::cout << this->brain->getBrainIdea(i) << RESET << std::endl;
}

void Dog::setBrainIdea(int i, std::string idea)
{
	brain->setBrainIdea(i, idea);
}
