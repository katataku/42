#include "Brain.hpp"

Brain::Brain()
{

	std::cout << GREEN << "Brain constructor" << RESET << std::endl;
}

Brain::~Brain()
{
	std::cout << RED << "Brain destructor" << RESET << std::endl;
}

Brain::Brain(const Brain &f)
{
	*this = f;
	std::cout << GREEN << "Brain constructor" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &f)
{
	for (int i = 0; i < 10; i++)
	{
		ideas[i] = f.ideas[i];
	}
	return *this;
}

std::string Brain::getBrainIdea(int i) const
{
	return (ideas[i]);
}

void Brain::setBrainIdea(int i, std::string idea)
{
	ideas[i] = idea;
}

