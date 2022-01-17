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
	WrongCat(const WrongCat &);

	WrongCat &operator=(const WrongCat &);

	void makeSound() const;
};

#endif
