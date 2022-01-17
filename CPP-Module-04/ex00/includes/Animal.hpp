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
	~Animal();
	Animal(const Animal &);

	Animal &operator=(const Animal &);

	virtual void makeSound() const;
	std::string getType() const;
};

#endif
