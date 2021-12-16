#include "escape_sequence.hpp"
#include <fstream>
#include <iostream>
#include <regex>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << RED << "arg error" << std::endl;
		return (-1);
	}
	std::string line;
	std::string filename = argv[1];
	std::string before	 = argv[2];
	std::string after	 = argv[3];

	std::ifstream ifs(filename);
	filename = "replace." + filename;
	std::ofstream ofs(filename);

	if (ifs.fail() || ofs.fail())
	{
		std::cout << RED << "fileopen error" << std::endl;
		return (-1);
	}
	while (std::getline(ifs, line))
	{
		line = regex_replace(line, std::regex(before), after);
		ofs << line;
		if (!ifs.eof())
			ofs << std::endl;
	}
	return (0);
}