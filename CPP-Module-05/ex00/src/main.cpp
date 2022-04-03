#include "Bureaucrat.hpp"

int main(void)
{

	Bureaucrat *a = new Bureaucrat("a", 2);
	Bureaucrat *b = new Bureaucrat("b", 149);

	try
	{
		std::cout << *a << std::endl;
		a->incrementGrade();
		std::cout << *a << std::endl;
		//		a->incrementGrade();

		std::cout << *b << std::endl;
		b->decrementGrade();
		std::cout << *b << std::endl;
		//		b->decrementGrade();
	} catch (std::exception & e)
	{
		std::cout << RED << e.what() << std::endl;
	}
	delete a;
	delete b;
}