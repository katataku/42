#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: Form("ShrubberyCreation",145, 137), target("no name")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: Form("ShrubberyCreation",145, 137), target(target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &f)
: Form(f.getName(),f.getGradeRequiredToSign(),f.getGradeRequiredToExecute()),target(f.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &f)
{
	target = f.target;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &f)
{
	os << f.getName() << std::endl;
	return os;
}

const char* ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char* ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

const char* ShrubberyCreationForm::NotSignedException::what() const throw()
{
	return "NotSignedException";
}

void ShrubberyCreationForm::execute(Bureaucrat const &b) const
{
	std::ofstream newFile;
	std::string filename = this->target + "_shrubbery";

	if (this->getIsSigned() == false)
		throw ShrubberyCreationForm::NotSignedException();
	if (b.getGrade() > getGradeRequiredToExecute())
		throw ShrubberyCreationForm::GradeTooLowException();

	newFile.open(filename, std::ios::out);
	if (!newFile)
		throw std::runtime_error("Open failed");
	newFile << "                  x       " << std::endl;
	newFile << "            /----- -----\\       " << std::endl;
	newFile << "            x           x       " << std::endl;
	newFile << "         /-- --\\     /-- --\\       " << std::endl;
	newFile << "        x      x     x     x       "<< std::endl;
	newFile << "       / \\    / \\   / \\   / \\       " << std::endl;
	newFile << "       x x    x x   x x   x x       " << std::endl;
	if (newFile.fail())
		throw std::runtime_error("Write failed");
	newFile.close();
}