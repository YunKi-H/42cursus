#include "WrongAnimal.hpp"

const std::string WrongAnimal::_className = "WrongAnimal";

WrongAnimal::WrongAnimal() : _type(this->_className) {
	std::cout << this->_className << " [" << this->_type << "] is born!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal) {
	*this = wrongAnimal;
	std::cout << this->_className << " [" << this->_type << "] is born!" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << this->_className << " [" << this->_type << "] is died.." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
	this->_type = rhs.getType();
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << this->_className << " [" << this->_type << "] : ..." << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->_type;
}

void WrongAnimal::setType(const std::string &type) {
	this->_type = type;
}
