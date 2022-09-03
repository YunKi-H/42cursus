#include "WrongCat.hpp"

const std::string WrongCat::_className = "WrongCat";

WrongCat::WrongCat() {
	this->_type = this->_className;
	std::cout << this->_className << " [" << this->_type << "] is born!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) {
	*this = wrongCat;
	std::cout << this->_className << " [" << this->_type << "] is born!" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << this->_className << " [" << this->_type << "] is died.." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
	this->_type = rhs.getType();
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << this->_className << " [" << this->_type << "] : Meow" << std::endl;
}
