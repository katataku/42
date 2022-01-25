#ifndef DOG_H
#define DOG_H

#include "escape_sequence.hpp"
#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog: public Animal
{
  public:
  	Dog();
	~Dog();
	Dog(const Dog &other);

	Dog &operator=(const Dog &other);

	void makeSound() const;
};

#endif
