#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{

	Intern *i = new Intern();
	Bureaucrat *a = new Bureaucrat("a", 2);
	Bureaucrat *b = new Bureaucrat("b", 149);
	Form *shrubbery = i->makeForm("shrubbery creation", "target1");
	std::cout << *a << std::endl;
	b->signForm(shrubbery);
	a->executeForm(shrubbery);
	a->signForm(shrubbery);
	a->executeForm(shrubbery);

	std::cout << std::endl;
	std::cout << std::endl;
	Form *Robotomy = i->makeForm("robotomy request", "target1");
	std::cout << *a << std::endl;
	b->signForm(Robotomy);
	a->executeForm(Robotomy);
	a->signForm(Robotomy);
	a->executeForm(Robotomy);
	
	std::cout << std::endl;
	std::cout << std::endl;
	Form *PresidentialPardon = i->makeForm("presidential pardon", "target1");
	std::cout << *a << std::endl;
	b->signForm(PresidentialPardon);
	a->executeForm(PresidentialPardon);
	a->signForm(PresidentialPardon);
	a->executeForm(PresidentialPardon);
	delete PresidentialPardon;
}