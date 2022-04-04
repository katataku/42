#ifndef FORM
#define FORM

#include "escape_sequence.hpp"
#include <exception>
#include <iostream>
#include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
  private:
	const std::string name;
	bool		isSigned;
	const int	gradeRequiredToSign;
	const int gradeRequiredToExecute;

  public:
	Form();
	~Form();
	Form(const Form &);
	Form &operator=(const Form &);

	Form(std::string name, int gradeRequiredToSign, const int gradeRequiredToExecute);
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExecute() const;

	void beSigned(Bureaucrat *);

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &, const Form &);

#endif
