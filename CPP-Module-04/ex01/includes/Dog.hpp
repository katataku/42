#ifndef Dog_H
#define Dog_H

#include "Animal.hpp"
#include "Brain.hpp"
#include "escape_sequence.hpp"
#include <iostream>
#include <string>

class Dog : public Animal
{
  private:
	Brain *brain;

  public:
	Dog();
	~Dog();
	Dog(const Dog &);

	Dog &operator=(const Dog &);

	void makeSound() const;
	void getBrainIdea(int i) const;
	void setBrainIdea(int i, std::string idea);
};

#endif
