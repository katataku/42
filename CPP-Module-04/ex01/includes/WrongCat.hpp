#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "escape_sequence.hpp"
#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
  public:
  	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat &other);

	WrongCat &operator=(const WrongCat &other);

	void makeSound() const;
};

#endif
