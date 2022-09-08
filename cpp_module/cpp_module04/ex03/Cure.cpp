#include "Cure.hpp"

const std::string Cure::_materiaName = "cure";

Cure::Cure() : AMateria(Cure::_materiaName) {
}

Cure::Cure(const Cure &cure) : AMateria(cure) {
	*this = cure;
}

Cure::~Cure() {
}

Cure &Cure::operator=(const Cure &rhs) {
	this->_type = rhs.getType();
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
