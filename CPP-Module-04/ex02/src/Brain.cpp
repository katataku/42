#include "Brain.hpp"

Brain::Brain()
{

	std::cout << GREEN << "Brain constructor" << RESET << std::endl;
}

Brain::~Brain()
{
	std::cout << RED << "Brain destructor" << RESET << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << GREEN << "Brain constructor" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = other.ideas[i];
	}
	return *this;
}

std::string Brain::getBrainIdea(int i) const
{
	return (ideas[i]);
}

void Brain::setBrainIdea(int i, std::string idea)
{
	if (0 <= i && i < 100)
		ideas[i] = idea;
}
