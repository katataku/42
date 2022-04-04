#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("no name"), grade(100)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}
Bureaucrat::Bureaucrat(const Bureaucrat &b)
{
	name  = b.name;
	grade = b.grade;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
	name  = b.name;
	grade = b.grade;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return name;
}
int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade()
{
	if (grade > 1)
		grade--;
	else
		throw GradeTooHighException();
}
void Bureaucrat::decrementGrade()
{
	if (grade < 150)
		grade++;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

void Bureaucrat::signForm(Form *f)
{
	try{
		if (f){
			f->beSigned(this);
			std::cout << this->getName() << " signed " << f->getName() << RESET << std::endl;
		}
	}
	catch(std::exception& e){
		std::cout <<RED << this->getName() << " couldn't sign " << f->getName() << " because " << e.what() << RESET<< std::endl;
	}
}

void Bureaucrat::executeForm(Form const  * f)
{
	try
	{
		
		f->execute(*this);
		std::cout << this->getName() << " executed " << f->getName() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout <<RED << this->getName() << " couldn't execute " << f->getName() << " because " << e.what() << RESET<< std::endl;
	}
	
}