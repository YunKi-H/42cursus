#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("a Bureaucrat"), _grade(Bureaucrat::_gradeLowest) {
}

Bureaucrat::Bureaucrat(const std::string &name) : _name(name), _grade(Bureaucrat::_gradeLowest) {
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) {
	*this = bureaucrat;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	const_cast<std::string &>(this->_name) = rhs.getName();
	this->_grade = rhs.getGrade();
	return *this;
}

const std::string &Bureaucrat::getName() const {
	return this->_name;
}

const int &Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::increGrade(const int &amount) {
	try {
		this->_grade -= amount;
		if (this->_grade < 1) {
			this->_grade = 1;
			throw Bureaucrat::GradeTooHighException();
		}
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::decreGrade(const int &amount) {
	try {
		this->_grade += amount;
		if (this->_grade > 150) {
			this->_grade = 150;
			throw Bureaucrat::GradeTooLowException();
		}
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade Too High!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade Too Low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	return out << bureaucrat.getName()
	<< ", bureaucrat grade " << bureaucrat.getGrade();
}
