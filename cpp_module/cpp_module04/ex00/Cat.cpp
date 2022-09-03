#include "Cat.hpp"

const std::string Cat::_className = "Cat";

Cat::Cat() {
	this->_type = this->_className;
	std::cout << this->_className << " [" << this->_type << "] is born!" << std::endl;
}

Cat::Cat(const Cat &cat) {
	*this = cat;
	std::cout << this->_className << " [" << this->_type << "] is born!" << std::endl;
}

Cat::~Cat() {
	std::cout << this->_className << " [" << this->_type << "] is died.." << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
	this->_type = rhs.getType();
	return *this;
}

void Cat::makeSound() const {
	std::cout << this->_className << " [" << this->_type << "] : Meow" << std::endl;
}
