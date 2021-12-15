#include "Karen.hpp"

Karen::Karen()
{
}
Karen::~Karen()
{
}
void Karen::complain(std::string level)
{
	int idx = (level == "DEBUG") + (level == "INFO") * 2
			+ (level == "WARNING") * 3 + (level == "ERROR") * 4;

	switch (idx) {
		case 1:
			Karen::debug();
			break;
		case 2:
			Karen::info();
			break;
		case 3:
			Karen::warning();
			break;
		case 4:
			Karen::error();
			break;
		default:
			break;
	}

}
void Karen::debug(void)
{
	std::cout << "I love to get extra bacon for my "
				 "7XL-double-cheese-triple-pickle-special-ketchup burger. I "
				 "just love it!"
			  << std::endl;
}
void Karen::info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money. You "
				 "don’t put enough! If you did I would not have to ask for it!"
			  << std::endl;
}
void Karen::warning(void)
{
	std::cout
		<< "I think I deserve to have some extra bacon for free. I’ve been "
		   "coming here for years and you just started working here last month."
		<< std::endl;
}
void Karen::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now."
			  << std::endl;
}
