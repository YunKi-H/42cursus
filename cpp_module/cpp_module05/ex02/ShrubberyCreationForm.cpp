#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::_className = "ShrubberyCreationForm";
const std::string ShrubberyCreationForm::_tree =
	"               ,@@@@@@@,\n"
	"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
	"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
	"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
	"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
	"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
	"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
	"       |o|        | |         | |\n"
	"       |.|        | |         | |\n"
	"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";

ShrubberyCreationForm::ShrubberyCreationForm() :
Form(this->_className, this->_signGrade, this->_excuteGrade),
_target("Anonymous") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
Form(this->_className, this->_signGrade, this->_excuteGrade),
_target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm) {
	*this = shrubberyCreationForm;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	this->_target = rhs._target;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &excutor) const {
	if (excutor.getGrade() > this->getGradeToSign()) {
		throw Form::GradeTooLowException();
	}
	if (this->getIsSigned() == 0) {
		throw Form::UnSignedException();
	}
	std::ofstream output(this->_target + "_shrubbery");
	if (output.fail()) {
		std::cerr << "FILE OPEN FAILED" << std::endl;
		exit(1);
	}
	output << this->_tree;
	output.close();
}
