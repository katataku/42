#include <iostream>
#include <iter.hpp>

void printArray(int a)
{
	std::cout << a << std::endl;
}

int main(int, char **)
{
	int array[10];
	for (int i = 0; i < 10; i++)
	{
		array[i] = i;
	}

	::iter(array, 10, printArray);

	return 0;
}