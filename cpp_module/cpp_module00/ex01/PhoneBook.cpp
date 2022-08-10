#include <iostream>
#include "PhoneBook.hpp"

void PhoneBook::addContact() {
	this->_contacts[this->_index % 8] = Contact(
		getInput("First name	 : "),
		getInput("Last name		 : "),
		getInput("Nick name		 : "),
		getInput("Phone number	 : "),
		getInput("Darkest secret : ")
	);
	this->_index += 1;
}

std::string	PhoneBook::getInput(std::string msg) {
	std::string	input;

	while (input.empty()) {
		std::cout << msg << std::endl;
		getline(std::cin, input);
	}
	return (input);
}

PhoneBook::PhoneBook() {
	this->_index = 0;
}

PhoneBook::~PhoneBook() {
	std::cout << "Thank you" << std::endl;
}
