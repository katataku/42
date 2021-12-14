#include <iostream>
#include "escape_sequence.hpp"
#include <string>
int main(void)
{
	std::string str = "HI THIS IS BRAIN";

	std::string*	stringPTR = &str;
	std::string&		stringREF = str;

	std::cout	<<"STR:"  
				<< std::hex 
				<< &str 
				<< RESET
				<< std::endl;
	std::cout << std::endl;


	std::cout	<< RED
				<<"PTR:" 
				<< std::hex 
				<< stringPTR 
				<< std::endl;
	std::cout 	<< GREEN
				<<"REF:" 
				<< std::hex 
				<< &stringREF 
				<< std::endl;

	std::cout << std::endl;

	std::cout	<< RED
				<< "PTR:" 
				<< *stringPTR 
				<< std::endl;

	std::cout	<< GREEN
				<< "REF:" 
				<< stringREF 
				<< std::endl;



	return (0);
}
