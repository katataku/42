#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"
#include "escape_sequence.hpp"
#include <iostream>
#include <string>

class Cat : public Animal
{
  private:
	Brain *brain;

  public:
	Cat();
	~Cat();
	Cat(Cat const &f);

	Cat &operator=(const Cat &);

	void makeSound() const;
	void getBrainIdea(int i) const;
	void setBrainIdea(int i, std::string idea);
};

#endif
