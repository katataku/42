#ifndef CURE
#define CURE

#include "escape_sequence.hpp"
#include <AMateria.hpp>
#include <ICharacter.hpp>

#include <iostream>
#include <string>
class Cure : public AMateria
{
  public:
	Cure();
	~Cure();
	Cure(const Cure &);
	Cure &operator=(const Cure &);

	std::string const &getType() const; // Returns the materia type
	AMateria			 *clone() const;
	void			   use(ICharacter &target);
};

#endif
