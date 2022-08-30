#include "DiamondTrap.hpp"

const std::string DiamondTrap::_unitType = "DiamondTrap";

DiamondTrap::DiamondTrap() {
	this->_name = "a DiamondTrap";
	this->_hp = this->_unitHp;
	this->_ep = this->_unitEp;
	this->_ad = this->_unitAd;
	std::cout << this->_unitType << " [" << this->_name << "] generated!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) {
	this->_name = name;
	this->_hp = this->_unitHp;
	this->_ep = this->_unitEp;
	this->_ad = this->_unitAd;
	std::cout << this->_unitType << " [" << this->_name << "] generated!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) {
	*this = diamondTrap;
	std::cout << this->_unitType << " [" << this->_name << "] generated!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << this->_unitType << " [" << this->_name << "] destroyed!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &rhs) {
	this->_name = rhs.getName();
	this->_hp = rhs.getHp();
	this->_ep = rhs.getEp();
	this->_ad = rhs.getAd();
	return *this;
}

void DiamondTrap::attack(const std::string& target) {
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

void DiamondTrap::whoAmI() const {
}
