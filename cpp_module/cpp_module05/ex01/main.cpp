#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	Form formA("A", 1, 1);
	Form formB("B", 150, 150);

	std::cout << formA << std::endl;
	std::cout << formB << std::endl;
	std::cout << std::endl;

	a.signForm(formA);
	a.signForm(formB);
	std::cout << std::endl;
	b.signForm(formA);
	b.signForm(formB);

	std::cout << std::endl;
	std::cout << formA << std::endl;
	std::cout << formB << std::endl;
}
