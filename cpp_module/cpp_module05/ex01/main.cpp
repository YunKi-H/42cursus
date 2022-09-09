#include "Bureaucrat.hpp"

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
}
