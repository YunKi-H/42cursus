#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
	Bureaucrat a("a");
	Bureaucrat b("b");

	std::cout << a << std::endl;
	a.increGrade(100);
	std::cout << a << std::endl;
	a.decreGrade(200);
	std::cout << a << std::endl;
	std::cout << std::endl;

	std::cout << b << std::endl;
	b.increGrade(200);
	std::cout << b << std::endl;
	std::cout << std::endl;

	// Form formA("A", 1, 1);
	// Form formB("B", 150, 150);

	// std::cout << formA << std::endl;
	// std::cout << formB << std::endl;
	// std::cout << std::endl;

	// a.signForm(formA);
	// a.signForm(formB);
	// std::cout << std::endl;
	// b.signForm(formA);
	// b.signForm(formB);

	// std::cout << std::endl;
	// std::cout << formA << std::endl;
	// std::cout << formB << std::endl;

	// ShrubberyCreationForm s("home");
	// b.executeForm(s);
	// std::cout << std::endl;
	// RobotomyRequestForm r("sad Tommy");
	// for (int i = 0; i < 4; i++) {
	// 	b.executeForm(r);
	// }
	// std::cout << std::endl;
	// PresidentialPardonForm p("poor Jean");
	// b.executeForm(p);
	// a.executeForm(p);
	// std::cout << std::endl;

	Intern intern;
	Form *form = intern.makeForm("ShrubberyCreationForm", "home");
	b.executeForm(*form);
	delete form;
	std::cout << std::endl;
	form = intern.makeForm("RobotomyRequestForm", "sad Tommy");
	for (int i = 0; i < 4; i++) {
		b.executeForm(*form);
	}
	delete form;
	std::cout << std::endl;
	form = intern.makeForm("PresidentialPardonForm", "poor Jean");
	b.executeForm(*form);
	a.executeForm(*form);
	std::cout << std::endl;
}
