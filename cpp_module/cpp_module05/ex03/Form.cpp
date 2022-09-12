#include "Form.hpp"

Form::Form() :
_name("a Form"),
_isSigned(false),
_gradeToSign(Form::_gradeHighest),
_gradeToExcute(Form::_gradeHighest) {
}


Form::Form(const std::string &name, const int gradeToSign, const int gradeToExcute) :
_name(name),
_isSigned(false),
_gradeToSign(gradeToSign),
_gradeToExcute(gradeToExcute) {
	try {
		if (this->_gradeToSign < Form::_gradeHighest
		|| this->_gradeToExcute < Form::_gradeHighest) {
			throw Form::GradeTooHighException();
		}
		if (this->_gradeToSign > Form::_gradeLowest
		|| this->_gradeToExcute > Form::_gradeLowest) {
			throw Form::GradeTooLowException();
		}
	}  catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

Form::Form(const Form &form) :
_name(form.getName()),
_isSigned(form.getIsSigned()),
_gradeToSign(form.getGradeToSign()),
_gradeToExcute(form.getGradeToExcute()) {
}

Form::~Form() {
}

Form &Form::operator=(const Form &rhs) {
	const_cast<std::string &>(this->_name) = rhs.getName();
	this->_isSigned = rhs.getIsSigned();
	const_cast<int &>(this->_gradeToSign) = rhs.getGradeToSign();
	const_cast<int &>(this->_gradeToExcute) = rhs.getGradeToExcute();
	return *this;
}

const std::string &Form::getName() const {
	return this->_name;
}

const bool &Form::getIsSigned() const {
	return this->_isSigned;
}

const int &Form::getGradeToSign() const {
	return this->_gradeToSign;
}

const int &Form::getGradeToExcute() const {
	return this->_gradeToExcute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->getGradeToSign()) {
		throw Form::GradeTooLowException();
	}
	this->_isSigned = true;
}

void Form::execute(const Bureaucrat &excutor) const {
	if (excutor.getGrade() > this->getGradeToExcute()) {
		throw Form::GradeTooLowException();
	}
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade Too High to this Form!";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade Too Low to this Form!";
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
	return out << form.getName()
	<< ", is Signed : " << form.getIsSigned()
	<< ", grade to Sign : " << form.getGradeToSign()
	<< ", grade to excute : " << form.getGradeToExcute();
}
