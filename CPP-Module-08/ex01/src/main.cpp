#include "Span.hpp"
#include "escape_sequence.hpp"
#include <iostream>

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		Span large_sp = Span(10002);
		large_sp.addNumber(-1);
		large_sp.addNumber(10000000);
		large_sp.addNumber(10000,10);

		std::cout << large_sp.shortestSpan() << std::endl;
		std::cout << large_sp.longestSpan() << std::endl;

		large_sp.addNumber(100);
		std::cout << "This message is invisible." << std::endl;

	} catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << '\n';
	}
	return 0;
}