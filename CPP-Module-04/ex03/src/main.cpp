#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"


int main()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
 	ICharacter *me = new Character("me");
 	AMateria	 *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
 	ICharacter *bob = new Character("bob");
 	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	// IMateriaSource *src2 = new MateriaSource();
	// src2->learnMateria(new Ice());
	// src2->learnMateria(new Cure());
 	// Character *a = new Character("aaa");
	// tmp = src2->createMateria("ice");
	// a->equip(tmp);
	// tmp = src2->createMateria("cure");
	// a->equip(tmp);
	// delete src2;
	// Character *b = new Character(*a);
 	// a->use(0, *b);
	// a->use(1, *b);
	// delete a;
 	// b->use(0, *b);
	// b->use(1, *b);
	// delete b;

	//system("leaks a.out");
	return 0;
}