#include "RobotomyRequestForm.hpp"

const std::string RobotomyRequestForm::_className = "RobotomyRequestForm";

RobotomyRequestForm::RobotomyRequestForm() :
Form(this->_className, this->_signGrade, this->_excuteGrade),
_target("Anonymous") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
Form(this->_className, this->_signGrade, this->_excuteGrade),
_target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm) {
	*this = robotomyRequestForm;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	this->_target = rhs._target;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &excutor) const {
	if (excutor.getGrade() > this->getGradeToSign()) {
		throw Form::GradeTooLowException();
	}
	struct timeval	time;
	gettimeofday(&time, NULL);
	srand(time.tv_usec);
	if (rand() % 2 == 0) {
		std::cout << this->_target << " robotomized SUCCESS!" << std::endl;
	} else {
		std::cout << this->_target << " robotomized FAILED.." << std::endl;
	}
}

