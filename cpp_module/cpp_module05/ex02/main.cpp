#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	Bureaucrat a("a", 150);
	Bureaucrat b("b", 1);

	std::cout << a << std::endl;
	a.increGrade();
	std::cout << a << std::endl;
	a.decreGrade();
	a.decreGrade();
	std::cout << a << std::endl;
	std::cout << std::endl;

	std::cout << b << std::endl;
	b.increGrade();
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
	ShrubberyCreationForm s("home");
	b.executeForm(s);
	std::cout << std::endl;
	RobotomyRequestForm r("sad Tommy");
	for (int i = 0; i < 4; i++) {
		b.executeForm(r);
	}
	std::cout << std::endl;
	PresidentialPardonForm p("poor Jean");
	b.executeForm(p);
	a.executeForm(p);
}
