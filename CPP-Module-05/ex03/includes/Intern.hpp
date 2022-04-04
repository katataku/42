#ifndef INTERN
#define INTERN

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
	Intern();
	~Intern();
	Intern(const Intern &);
	Intern &operator=(const Intern &);


	Form *makeShrubberyCreation(const std::string &) const;
	Form *makeRobotomyRequest(const std::string &) const;
	Form *makePresidentialPardon(const std::string &) const;
	Form *makeForm(const std::string &form, const std::string &) const;
};

#endif
