#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("a Bureaucrat"), _grade(Bureaucrat::_gradeLowest) {
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : _name(name), _grade(grade) {
	try {
		if (this->_grade < Bureaucrat::_gradeHighest) {
			this->_grade = Bureaucrat::_gradeHighest;
			throw Bureaucrat::GradeTooHighException();
		}
		if (this->_grade > Bureaucrat::_gradeHighest) {
			this->_grade = Bureaucrat::_gradeLowest;
			throw Bureaucrat::GradeTooLowException();
		}
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
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

void Bureaucrat::increGrade() {
	try {
		this->_grade -= 1;
		if (this->_grade < Bureaucrat::_gradeHighest) {
			this->_grade = Bureaucrat::_gradeHighest;
			throw Bureaucrat::GradeTooHighException();
		}
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::decreGrade() {
	try {
		this->_grade += 1;
		if (this->_grade > Bureaucrat::_gradeLowest) {
			this->_grade = Bureaucrat::_gradeLowest;
			throw Bureaucrat::GradeTooLowException();
		}
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(const Form &form) {
	try {
		const_cast<Form &>(form).beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	} catch(const std::exception& e) {
		std::cerr << this->getName() << " couldn't signed "
		<< form.getName() << " because " << e.what() << std::endl;
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
