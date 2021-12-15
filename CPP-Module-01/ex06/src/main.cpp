#include "Karen.hpp"
#include "escape_sequence.hpp"
#include <fstream>
#include <iostream>
#include <regex>

int main(int argc, char **argv)
{
	Karen karen;
	std::string level = argv[argc - 1];

	karen.complain(level);
	std::cout << std::endl;
	return (0);
}