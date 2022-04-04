#include "Bureaucrat.hpp"

int main(void)
{

	Bureaucrat *a = new Bureaucrat("a", 2);
	Bureaucrat *b = new Bureaucrat("b", 149);
	Form *f = new Form("form", 10, 20);
	std::cout << *a << std::endl;
	a->signForm(f);

	std::cout << *b << std::endl;
	b->signForm(f);
}