#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include "escape_sequence.hpp"
#include <iostream>
#include <string>
class WrongAnimal
{
  protected:
	std::string	 type;

  public:
  	WrongAnimal();
	WrongAnimal(std::string name);
	~WrongAnimal();
	WrongAnimal(const WrongAnimal &other);

	WrongAnimal &operator=(const WrongAnimal &other);

	void makeSound() const;
	std::string getType() const;
};

#endif
