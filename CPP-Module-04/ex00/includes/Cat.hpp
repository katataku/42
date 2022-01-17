#ifndef CAT_H
#define CAT_H

#include "escape_sequence.hpp"
#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat: public Animal
{
  public:
  	Cat();
	~Cat();
	Cat(const Cat &);

	Cat &operator=(const Cat &);

	void makeSound() const;
};

#endif
