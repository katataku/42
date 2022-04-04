#include "Form.hpp"

Form::Form()
: name("no name"), isSigned(false),gradeRequiredToSign(10), gradeRequiredToExecute(10)
{

}

Form::~Form()
{

}

Form::Form(const Form &f): name(f.name),isSigned(f.isSigned),gradeRequiredToSign(f.gradeRequiredToExecute),gradeRequiredToExecute(f.gradeRequiredToExecute)
{
}

Form &Form::operator=(const Form &f)
{
	isSigned = f.isSigned;
	return *this;
}


Form::Form(std::string name, int gradeRequiredToSign, const int gradeRequiredToExecute)
: name(name), isSigned(false),gradeRequiredToSign(gradeRequiredToSign), gradeRequiredToExecute(gradeRequiredToExecute)
{

}

std::string Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getGradeRequiredToSign() const
{
	return gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const
{
	return gradeRequiredToExecute;
}


void Form::beSigned(Bureaucrat *f)
{
	if (f->getGrade() > gradeRequiredToSign)
		throw GradeTooLowException();
	else
		isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << f.getName() << std::endl;
	return os;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}