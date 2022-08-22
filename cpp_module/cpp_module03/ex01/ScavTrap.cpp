#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : _name("a ScavTrap"), _hp(100), _ep(50), _ad(20) {
	std::cout << "ScavTrap [" << this->_name << "] generated!" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : _name(name), _hp(100), _ep(50), _ad(20) {
	std::cout << "ScavTrap [" << this->_name << "] generated!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) {
	*this = scavTrap;
	std::cout << "ScavTrap [" << this->_name << "] generated!" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap [" << this->_name << "] destroyed!" << std::endl;
}

void ScavTrap::guardGate() const {
	std::cout << "ScavTrap [" << this->_name
	<< "] is now on Gatekeeper Mode!" << std::endl;
}
