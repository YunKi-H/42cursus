#include "Ice.hpp"

const std::string Ice::_materiaName = "ice";

Ice::Ice() : AMateria(Ice::_materiaName) {
}

Ice::Ice(const Ice &ice) : AMateria(ice) {
	*this = ice;
}

Ice::~Ice() {
}

Ice &Ice::operator=(const Ice &rhs) {
	this->_type = rhs.getType();
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
