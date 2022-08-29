#include "ScavTrap.hpp"

const std::string ScavTrap::_unitType = "ScavTrap";

ScavTrap::ScavTrap() {
	this->_name = "a ScavTrap";
	this->_hp = this->_unitHp;
	this->_ep = this->_unitEp;
	this->_ad = this->_unitAd;
	std::cout << this->_unitType << " [" << this->_name << "] generated!" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) {
	this->_name = name;
	this->_hp = this->_unitHp;
	this->_ep = this->_unitEp;
	this->_ad = this->_unitAd;
	std::cout << this->_unitType << " [" << this->_name << "] generated!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) {
	*this = scavTrap;
	std::cout << this->_unitType << " [" << this->_name << "] generated!" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << this->_unitType << " [" << this->_name << "] destroyed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &rhs) {
	this->_name = rhs.getName();
	this->_hp = rhs.getHp();
	this->_ep = rhs.getEp();
	this->_ad = rhs.getAd();
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (!this->_hp || !this->_ep) {
		std::cout << this->_unitType << " ["
		<< this->_name
		<< "] can`t move anymore!" << std::endl;
		return;
	}
	std::cout << this->_unitType << " ["
	<< this->_name
	<< "] makes a strong attack to ["
	<< target
	<< "], causing "
	<< this->_ad
	<< " points of damage!" << std::endl;
	this->_ep -= 1;
}

void ScavTrap::guardGate() const {
	std::cout << this->_unitType << " [" << this->_name
	<< "] is now on Gatekeeper Mode!" << std::endl;
}
