#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	static const int _gradeHighest = 1;
	static const int _gradeLowest = 150;

	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExcute;
public:
	Form();
	Form(const std::string &name, const int gradeToSign, const int gradeToExcute);
	Form(const Form &form);
	virtual ~Form();

	Form &operator=(const Form &rhs);

	const std::string &getName() const;
	const bool &getIsSigned() const;
	const int &getGradeToSign() const;
	const int &getGradeToExcute() const;
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(const Bureaucrat &excutor) const = 0;

	class GradeTooHighException : public std::exception {
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		const char *what() const throw();
	};

	class UnSignedException : public std::exception {
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
