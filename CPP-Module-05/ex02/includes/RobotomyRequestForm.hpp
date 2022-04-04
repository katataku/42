#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "escape_sequence.hpp"
#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm: public Form
{
  private:
	std::string target;

  public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &);

	RobotomyRequestForm(std::string);
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
