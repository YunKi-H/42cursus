#include "PresidentialPardonForm.hpp"

const std::string PresidentialPardonForm::_className = "PresidentialPardonForm";

PresidentialPardonForm::PresidentialPardonForm() :
Form(this->_className, this->_signGrade, this->_excuteGrade),
_target("Anonymous") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
Form(this->_className, this->_signGrade, this->_excuteGrade),
_target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm) {
	*this = presidentialPardonForm;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	this->_target = rhs._target;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &excutor) const {
	if (excutor.getGrade() > this->getGradeToSign()) {
		throw Form::GradeTooLowException();
	}
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

