#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
#include <limits>

static void printWrongValue() {
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "cloat: " << "nanf" << std::endl;
	std::cout << "double: " << "nan" << std::endl;
}

static void printChar(double d) {
	std::cout << "char: ";
	if (static_cast<int>(d) == d && isprint(d) == true) {
		std::cout << "'" << static_cast<char>(d) << "'";
	} else {
		std::cout << "Non displayable";
	}
	std::cout << std::endl;
}

static void printInt(double d) {
	int i = static_cast<int>(d);
	std::cout << "int: " << i << std::endl;
}

static void printFloat(double d) {
	float f = static_cast<float>(d);
	std::cout << "float: " << f;
	if (f == static_cast<int>(d)) {
		std::cout << ".0";
	}
	std::cout << "f" << std::endl;
}

static void printDouble(double d) {
	std::cout << "double: " << d;
	if (d == static_cast<int>(d)) {
		std::cout << ".0";
	}
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "USAGE : ./convert LITERAL" << std::endl;
		return 0;
	}
	char *endptr = NULL;
	double input = (strlen(argv[1]) == 1 && isprint(argv[1][0]) && !isdigit(argv[1][0]))
	? static_cast<double>(argv[1][0])
	: strtod(argv[1], &endptr);
	if ((endptr && *endptr != '\0' && std::string(endptr) != "f") || isnan(input)) {
		printWrongValue();
		return 0;
	}
	printChar(input);
	printInt(input);
	printFloat(input);
	printDouble(input);
}
