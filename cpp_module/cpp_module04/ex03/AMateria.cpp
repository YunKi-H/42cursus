#include "AMateria.hpp"

const std::string AMateria::_className = "AMateria";

AMateria::AMateria() : _type("a Materia") {
	// std::cout << this->_className << " [" << this->_type << "] generated!" << std::endl;
}

AMateria::AMateria(const AMateria &amateria) {
	// std::cout << this->_className << " [" << this->_type << "] generated!" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {
	// std::cout << this->_className << " [" << this->_type << "] generated!" << std::endl;
}

AMateria::~AMateria() {
	// std::cout << this->_className << " [" << this->_type << "] destructed!" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &rhs) {
	this->_type = rhs.getType();
	return *this;
}

std::string const &AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	// std::cout << this->_className << " [" << this->_type << "] is used to ["
	// << target.getName() << "]" << std::endl;
}
