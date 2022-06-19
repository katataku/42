#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vector = std::vector<int>(3);

	vector[0] = 1;
	vector[1] = 2;
	vector[2] = 3;

	try
	{
		std::vector<int>::iterator it_v;
		it_v = easyfind(vector, 2);

		while (it_v != vector.end())
		{
			std::cout << *it_v;
			it_v++;
		}
		std::cout << std::endl;
	} catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << '\n';
	}
}