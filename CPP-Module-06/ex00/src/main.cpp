#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "required one argument" << std::endl;
		return (1);
	}


	Convert c = Convert(argv[1]);
	c.printChar();
	c.printInt();
	c.printFloat();
	c.printDouble();
	return (0);
}
