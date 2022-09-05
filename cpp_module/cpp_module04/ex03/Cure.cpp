#include "Cure.hpp"

const std::string Cure::_className = "Cure";
const std::string Cure::_materiaName = "cure";

Cure::Cure() : AMateria(Cure::_materiaName) {
	std::cout << this->_className << " generated!" << std::endl;
}

Cure::Cure(const Cure &cure) : AMateria(cure.getType()) {
	std::cout << this->_className << " generated!" << std::endl;
}

Cure::~Cure() {
	std::cout << this->_className << " destructed!" << std::endl;
}

Cure &Cure::operator=(const Cure &rhs) {
	this->_type = rhs.getType();
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << this->_className
	<< " * heals "
	<< target.getName() << "'s wounds *" << std::endl;
}
