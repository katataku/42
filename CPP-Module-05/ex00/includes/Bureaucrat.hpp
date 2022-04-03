#ifndef BUREAUCRAT
#define BUREAUCRAT

#include "escape_sequence.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
  private:
	std::string name;
	int			grade;

  public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &);
	Bureaucrat &operator=(const Bureaucrat &);

	Bureaucrat(std::string name, int grade);
	std::string getName() const;
	int			getGrade() const;

	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);

#endif
