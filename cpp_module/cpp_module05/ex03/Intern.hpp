#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
private:
	static const std::string _className;
public:
	Intern();
	Intern(const Intern &intern);
	virtual ~Intern();

	Intern &operator=(const Intern &rhs);

	Form *makeForm(const std::string &formName, const std::string formTarget);

	class WrongFormException : public std::exception {
		const char *what() const throw();
	};
};

#endif
