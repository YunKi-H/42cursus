#include "Animal.hpp"

const std::string Animal::_className = "Animal";

Animal::Animal() : _type(this->_className) {
	std::cout << this->_className << " [" << this->_type << "] is born!" << std::endl;
}

Animal::Animal(const Animal &animal) {
	*this = animal;
	std::cout << this->_className << " [" << this->_type << "] is born!" << std::endl;
}

Animal::~Animal() {
	std::cout << this->_className << " [" << this->_type << "] is died.." << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
	this->_type = rhs.getType();
	return *this;
}

void Animal::makeSound() const {
	std::cout << this->_className << " [" << this->_type << "] : ..." << std::endl;
}

std::string Animal::getType() const {
	return this->_type;
}

void Animal::setType(const std::string &type) {
	this->_type = type;
}
