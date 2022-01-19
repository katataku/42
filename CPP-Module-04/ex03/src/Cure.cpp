#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::~Cure()
{
}

Cure::Cure(const Cure &other) : AMateria("cure")
{
	*this = other;
}

Cure &Cure::operator=(const Cure &other)
{
	type = other.type;
	return *this;
}

AMateria *Cure::clone() const
{
	Cure *cure = new Cure();
	return cure;
}

void Cure::use(ICharacter &target)
{
	std::cout <<  "* heals " << target.getName() << "'s wounds *"
			  << std::endl;
}
