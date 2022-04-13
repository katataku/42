#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	srand(time(NULL));
	switch (rand() % 3)
	{
	case 0:
		std::cout << "A" << std::endl;
		return new A();
	case 1:
		std::cout << "B" << std::endl;
		return new B();
	case 2:
		std::cout << "C" << std::endl;
		return new C();
	}
	return NULL;
}

void identify(Base *p)
{
	std::cout << "*p: ";
	if (dynamic_cast<A *>(p) != nullptr)
	{
		std::cout << "A" << std::endl;
		return;
	}
	if (dynamic_cast<B *>(p) != nullptr)
	{
		std::cout << "B" << std::endl;
		return;
	}
	if (dynamic_cast<C *>(p) != nullptr)
	{
		std::cout << "C" << std::endl;
		return;
	}
}

void identify(Base &p)
{
	std::cout << "&p: ";
	try
	{
		static_cast<void>(dynamic_cast<A &>(p));
		std::cout << "A" << std::endl;
		return;
	} catch (std::bad_cast)
	{
	}
	try
	{
		static_cast<void>(dynamic_cast<B &>(p));
		std::cout << "B" << std::endl;
		return;
	} catch (std::bad_cast)
	{
	}
	try
	{
		static_cast<void>(dynamic_cast<C &>(p));
		std::cout << "C" << std::endl;
		return;
	} catch (std::bad_cast)
	{
	}
}

int main(void)
{
	Base *base = generate();
	identify(base);
	identify(*base);
	return (0);
}
