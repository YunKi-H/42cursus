#include "Intern.hpp"

const std::string Intern::_className = "Intern";

Intern::Intern() {
}

Intern::Intern(const Intern &intern) {
	(void)intern;
}

Intern::~Intern() {
}

Intern &Intern::operator=(const Intern &rhs) {
	(void)rhs;
	return *this;
}

Form *Intern::makeForm(const std::string &formName, const std::string formTarget) {
	Form *form = NULL;
	try {
		const std::string forms[3] = {
			"PresidentialPardonForm",
			"RobotomyRequestForm",
			"ShrubberyCreationForm"
		};
		int name;
		for (name = 0; name < 3; name++) {
			if (formName == forms[name]) {
				break;
			}
		}
		switch (name) {
		case 0:
			form = new PresidentialPardonForm(formTarget);
			break;
		case 1:
			form = new RobotomyRequestForm(formTarget);
			break;
		case 2:
			form = new ShrubberyCreationForm(formTarget);
			break;
		default:
			throw WrongFormException();
			break;
		}
		std::cout << this->_className << " creates " << form->getName() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return form;
}

const char *Intern::WrongFormException::what() const throw() {
	return "Wrong Form Format!";
}
