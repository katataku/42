#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: Form("RobotomyRequest",72, 45), target("no name")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: Form("RobotomyRequest",72, 45), target(target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &f)
: Form(f.getName(),f.getGradeRequiredToSign(),f.getGradeRequiredToExecute()),target(f.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &f)
{
	target = f.target;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &f)
{
	os << f.getName() << std::endl;
	return os;
}

const char* RobotomyRequestForm::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char* RobotomyRequestForm::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

const char* RobotomyRequestForm::NotSignedException::what() const throw()
{
	return "NotSignedException";
}

void RobotomyRequestForm::execute(Bureaucrat const &b) const
{

	if (this->getIsSigned() == false)
		throw RobotomyRequestForm::NotSignedException();
	if (b.getGrade() > getGradeRequiredToExecute())
		throw RobotomyRequestForm::GradeTooLowException();

	std::srand(std::time(NULL));
	int r = rand();
	std::cout << "gata gata " << std::endl;
	if (r % 2 == 0)
		std::cout << this->target << " has been robotomize." << std::endl;
	else
		std::cout << RED << this->target << " failed robotomize." << RESET << std::endl;
}