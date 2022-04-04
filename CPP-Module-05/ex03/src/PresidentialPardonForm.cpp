#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: Form("PresidentialPardonForm",25, 5), target("no name")
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: Form("PresidentialPardonForm",25, 5), target(target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &f)
: Form(f.getName(),f.getGradeRequiredToSign(),f.getGradeRequiredToExecute()),target(f.target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &f)
{
	target = f.target;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &f)
{
	os << f.getName() << std::endl;
	return os;
}

const char* PresidentialPardonForm::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char* PresidentialPardonForm::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

const char* PresidentialPardonForm::NotSignedException::what() const throw()
{
	return "NotSignedException";
}

void PresidentialPardonForm::execute(Bureaucrat const &b) const
{

	if (this->getIsSigned() == false)
		throw PresidentialPardonForm::NotSignedException();
	if (b.getGrade() > getGradeRequiredToExecute())
		throw PresidentialPardonForm::GradeTooLowException();

	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}