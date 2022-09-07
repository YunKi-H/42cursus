#include "Ice.hpp"

const std::string Ice::_className = "Ice";
const std::string Ice::_materiaName = "ice";

Ice::Ice() : AMateria(Ice::_materiaName) {
	// std::cout << this->_className << " generated!" << std::endl;
}

Ice::Ice(const Ice &ice) : AMateria(ice.getType()) {
	// std::cout << this->_className << " generated!" << std::endl;
}

Ice::~Ice() {
	// std::cout << this->_className << " destructed!" << std::endl;
}

Ice &Ice::operator=(const Ice &rhs) {
	this->_type = rhs.getType();
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << this->_className
	<< " * shoots an ice bolt at "
	<< target.getName() << " *" << std::endl;
}
