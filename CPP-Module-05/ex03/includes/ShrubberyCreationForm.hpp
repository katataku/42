#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include "escape_sequence.hpp"
#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm: public Form
{
  private:
	std::string target;

  public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);

	ShrubberyCreationForm(std::string);
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


