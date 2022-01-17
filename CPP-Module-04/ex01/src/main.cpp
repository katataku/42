#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << "----" << std::endl;


	Animal *array[10];
	for (int i = 0; i < 10; i++)
	{
		std::cout << "--" << i << "--" << std::endl;
		if (i <5)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << "--" << i << "--" << std::endl;
		delete array[i];
	}

	std::cout << "----" << std::endl;

	Cat *c = new Cat();
	c->setBrainIdea(0,"cat food");
	c->setBrainIdea(1,"cat food2");

	Cat *d = new Cat(*c);
	d->setBrainIdea(0,"dat food");
	d->setBrainIdea(1,"dat food2");

	c->getBrainIdea(0);
	c->getBrainIdea(1);
	delete c;

	d->getBrainIdea(0);
	d->getBrainIdea(1);
	delete d;
}