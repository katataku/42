#ifndef Brain_H
#define Brain_H

#include "escape_sequence.hpp"
#include <iostream>
#include <string>
class Brain
{
  public:
	std::string ideas[100];
  	Brain();
	~Brain();
	Brain(const Brain &);

	Brain &operator=(const Brain &);

	std::string getBrainIdea(int i) const;
	void setBrainIdea(int i, std::string idea);
};

#endif
