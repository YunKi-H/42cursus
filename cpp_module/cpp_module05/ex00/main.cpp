#include "Bureaucrat.hpp"

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
}
