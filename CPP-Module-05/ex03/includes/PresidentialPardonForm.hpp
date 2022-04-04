#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "escape_sequence.hpp"
#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm: public Form
{
  private:
	std::string target;

  public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &);

	PresidentialPardonForm(std::string);
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class NotSignedException : public std::exception
	{
		virtual const char* what() const throw();
	};


	virtual void execute(Bureaucrat const &) const;
};

std::ostream &operator<<(std::ostream &, const Form &);


#endif
