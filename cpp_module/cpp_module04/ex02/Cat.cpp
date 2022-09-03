#include "Cat.hpp"

const std::string Cat::_className = "Cat";

Cat::Cat() {
	this->_type = this->_className;
	this->_brain = new Brain();
	std::cout << this->_className << " [" << this->_type << "] is born!" << std::endl;
}

Cat::Cat(const Cat &cat) {
	*this = cat;
	std::cout << this->_className << " [" << this->_type << "] is born!" << std::endl;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << this->_className << " [" << this->_type << "] is died.." << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
	this->_type = rhs.getType();
	delete this->_brain;
	this->_brain = new Brain();
	for (int i = 0; i < this->_brain->getCapacity(); ++i) {
		this->_brain->setIdea(i, rhs._brain->getIdea(i));
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << this->_className << " [" << this->_type << "] : Meow" << std::endl;
}

Brain *Cat::getBrain() const {
	return this->_brain;
}
