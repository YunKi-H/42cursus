#include "Dog.hpp"

const std::string Dog::_className = "Dog";

Dog::Dog() {
	this->_type = this->_className;
	std::cout << this->_className << " [" << this->_type << "] is born!" << std::endl;
}

Dog::Dog(const Dog &dog) {
	*this = dog;
	std::cout << this->_className << " [" << this->_type << "] is born!" << std::endl;
}

Dog::~Dog() {
	std::cout << this->_className << " [" << this->_type << "] is died.." << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
	this->_type = rhs.getType();
	return *this;
}

void Dog::makeSound() const {
	std::cout << this->_className << " [" << this->_type << "] : Bark" << std::endl;
}
