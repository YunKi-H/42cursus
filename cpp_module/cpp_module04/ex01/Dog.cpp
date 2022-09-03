#include "Dog.hpp"

const std::string Dog::_className = "Dog";

Dog::Dog() {
	this->_type = this->_className;
	this->_brain = new Brain();
	std::cout << this->_className << " [" << this->_type << "] is born!" << std::endl;
}

Dog::Dog(const Dog &dog) {
	*this = dog;
	this->_brain = new Brain();
	for (int i = 0; i < this->_brain->getCapacity(); ++i) {
		this->_brain->setIdea(i, dog._brain->getIdea(i));
	}
	std::cout << this->_className << " [" << this->_type << "] is born!" << std::endl;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << this->_className << " [" << this->_type << "] is died.." << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
	this->_type = rhs.getType();
	delete this->_brain;
	this->_brain = new Brain();
	for (int i = 0; i < this->_brain->getCapacity(); ++i) {
		this->_brain->setIdea(i, rhs._brain->getIdea(i));
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << this->_className << " [" << this->_type << "] : Bark" << std::endl;
}

const Brain *Dog::getBrain() const {
	return this->_brain;
}
