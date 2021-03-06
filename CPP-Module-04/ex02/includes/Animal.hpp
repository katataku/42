#ifndef ANIMAL_H
#define ANIMAL_H

#include "escape_sequence.hpp"
#include <iostream>
#include <string>
class Animal
{
  protected:
	std::string	 type;

  public:
  	Animal();
	virtual ~Animal();
	Animal(const Animal &other);

	Animal &operator=(const Animal &other);

	virtual void makeSound() const = 0;
	std::string getType() const;

	void getBrainIdea(int i) const;
};

#endif
