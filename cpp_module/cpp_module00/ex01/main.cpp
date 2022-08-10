#include <iostream>
#include "PhoneBook.hpp"

int	main() {
	PhoneBook	pb;

	std::cout << "Welcome to PhoneBook" << std::endl;
	while (true) {
		std::string command = pb.getCommand();
		if (command == "ADD") {
			pb.add();
		} else if (command == "SEARCH") {
			pb.search();
		} else if (command == "EXIT") {
			std::cout << "Thank you" << std::endl;
			std::exit(0);
		} else {
			std::cout << "Wrong Command" << std::endl;
		}
	}
}
