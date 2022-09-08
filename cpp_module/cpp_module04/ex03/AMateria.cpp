#include "AMateria.hpp"

AMateria::AMateria() : _type("a Materia") {
}

AMateria::AMateria(const AMateria &amateria) {
	this->_type = amateria.getType();
}

AMateria::AMateria(std::string const & type) : _type(type) {
}

AMateria::~AMateria() {
}

AMateria &AMateria::operator=(const AMateria &rhs) {
	this->_type = rhs.getType();
	return *this;
}

std::string const &AMateria::getType() const {
	return this->_type;
}

AMateria* AMateria::clone() const {
	return NULL;
}

void AMateria::use(ICharacter& target) {
	std::cout << this->getType()
	<< " is used to " << target.getName() << std::endl;
}
