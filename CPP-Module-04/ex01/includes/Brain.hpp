#ifndef Brain_H
#define Brain_H

#include "escape_sequence.hpp"
#include <iostream>
#include <string>
class Brain
{
  private:
	std::string ideas[100];

  public:
	Brain();
	~Brain();
	Brain(const Brain &);

	Brain &operator=(const Brain &other);

	std::string getBrainIdea(int i) const;
	void		setBrainIdea(int i, std::string idea);
};

#endif
