#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

std::string	PhoneBook::_getInput(std::string msg) {
	std::string	input = "";

	while (input.empty()) {
		std::cout << msg;
		getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << "Thank you" << std::endl;
			std::exit(0);
		}
	}
	return (input);
}

void PhoneBook::_printInStyle(std::string str) {
	if (str.length() > 10) {
		str = str.substr(0, 10);
		str[9] = '.';
	}
	std::cout << std::setw(10);
	std::cout << str << '|';
}

void PhoneBook::_printContact(int index) const {
	std::cout << "First name     : " << this->_contacts[index].getFirstName() << std::endl;
	std::cout << "Last name      : " << this->_contacts[index].getLastName() << std::endl;
	std::cout << "Nick name      : " << this->_contacts[index].getNickName() << std::endl;
	std::cout << "Phone number   : " << this->_contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << this->_contacts[index].getDarkestSceret() << std::endl;
}

std::string PhoneBook::_toUpper(std::string str) {
	for (size_t i = 0; i < str.length(); i++) {
		str[i] = std::toupper(str[i]);
	}
	return (str);
}

std::string PhoneBook::getCommand() {
	std::cout << "Enter Command" << std::endl;
	return (_toUpper(_getInput("ADD / SEARCH / EXIT : ")));
}

void PhoneBook::add() {
	this->_contacts[this->_index % 8].setContact(
		_getInput("First name     : "),
		_getInput("Last name      : "),
		_getInput("Nick name      : "),
		_getInput("Phone number   : "),
		_getInput("Darkest secret : ")
	);
	this->_index += 1;
}

void PhoneBook::search() {
	_printInStyle("Index");
	_printInStyle("First name");
	_printInStyle("Last name");
	_printInStyle("Nick name");
	std::cout << std::endl;
	for (int i = 0; i < (this->_index < 8 ? this->_index : 8); i++) {
		_printInStyle(std::to_string(i));
		_printInStyle(this->_contacts[i].getFirstName());
		_printInStyle(this->_contacts[i].getLastName());
		_printInStyle(this->_contacts[i].getNickName());
		std::cout << std::endl;
	}
	int index;
	while (true) {
		index = -1;
		char *end;
		index = std::strtol(_getInput("Choose Index : ").c_str(), &end, 10);
		if (*end || index < 0 || index >= (this->_index < 8 ? this->_index : 8)) {
			std::cout << "Invalid Index" << std::endl;
		} else {
			break ;
		}
	}
	_printContact(index);
}

PhoneBook::PhoneBook() {
	this->_index = 0;
}

PhoneBook::~PhoneBook() {
}
