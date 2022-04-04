#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{

	Bureaucrat *a = new Bureaucrat("a", 2);
	Bureaucrat *b = new Bureaucrat("b", 149);
	ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm("targetfile");
	std::cout << *a << std::endl;
	b->signForm(shrubbery);
	a->executeForm(shrubbery);
	a->signForm(shrubbery);
	a->executeForm(shrubbery);

	std::cout << std::endl;
	std::cout << std::endl;
	RobotomyRequestForm *Robotomy = new RobotomyRequestForm("target");
	std::cout << *a << std::endl;
	b->signForm(Robotomy);
	a->executeForm(Robotomy);
	a->signForm(Robotomy);
	a->executeForm(Robotomy);
	
	std::cout << std::endl;
	std::cout << std::endl;
	PresidentialPardonForm *PresidentialPardon = new PresidentialPardonForm("target");
	std::cout << *a << std::endl;
	b->signForm(PresidentialPardon);
	a->executeForm(PresidentialPardon);
	a->signForm(PresidentialPardon);
	a->executeForm(PresidentialPardon);
}