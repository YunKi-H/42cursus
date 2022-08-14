#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl harl;

	if (argc != 2) {
		std::cout << "USAGE : ./harl [LEVEL : DEBUG, INFO, WARNING, ERROR]" << std::endl;
	} else {
		harl.complain(argv[1]);
	}
}
