#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &) {}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern &)
{
	return *this;
}

Form *Intern::makeShrubberyCreation(const std::string &target) const
{
	Form *form = new ShrubberyCreationForm(target);
	return form;
}

Form* Intern::makeRobotomyRequest(const std::string &target) const
{
	Form* form = new RobotomyRequestForm(target);
	return form;
}

Form* Intern::makePresidentialPardon(const std::string &target) const
{
	Form *form = new PresidentialPardonForm(target);
	return form;
}

Form* Intern::makeForm(const std::string &f, const std::string &target) const
{
	std::string formList[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form* (Intern::*funcList[3])(const std::string &) const =
		{&Intern::makeShrubberyCreation,
		&Intern::makeRobotomyRequest,
		&Intern::makePresidentialPardon};
	Form *rtn;

	for (int i = 0; i < 3; i++)
	{
		if (f == formList[i])
		{
			rtn = (this->*funcList[i])(target);
			return rtn;
		}
	}
	std::cout << RED << "There is no form with that name: " << f << RESET << std::endl;
	return NULL;
}
