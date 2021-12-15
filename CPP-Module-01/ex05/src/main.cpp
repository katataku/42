#include "Karen.hpp"
#include "escape_sequence.hpp"
#include <fstream>
#include <iostream>
#include <regex>

int main(void)
{
	Karen karen;

	karen.complain("DEBUG");
	karen.complain("INFO");
	karen.complain("WARNING");
	karen.complain("ERROR");
	return (0);
}