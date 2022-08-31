#include "FragTrap.hpp"

const std::string FragTrap::_unitType = "FragTrap";

FragTrap::FragTrap() {
	this->_name = "a FragTrap";
	this->_hp = this->_unitHp;
	this->_ep = this->_unitEp;
	this->_ad = this->_unitAd;
	std::cout << this->_unitType << " [" << this->_name << "] generated!" << std::endl;
}

FragTrap::FragTrap(const std::string name) {
	this->_name = name;
	this->_hp = this->_unitHp;
	this->_ep = this->_unitEp;
	this->_ad = this->_unitAd;
	std::cout << this->_unitType << " [" << this->_name << "] generated!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragTrap) {
	*this = fragTrap;
	std::cout << this->_unitType << " [" << this->_name << "] generated!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << this->_unitType << " [" << this->_name << "] destroyed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &rhs) {
	this->_name = rhs.getName();
	this->_hp = rhs.getHp();
	this->_ep = rhs.getEp();
	this->_ad = rhs.getAd();
	return *this;
}

void FragTrap::attack(const std::string& target) {
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

void FragTrap::highFivesGuys() const {
	std::cout << this->_unitType << " [" << this->_name
	<< "] ask High Fives to you!" << std::endl;
}

std::string FragTrap::getUnitType() const {
	return this->_unitType;
}

unsigned int FragTrap::getUnitHp() const {
	return this->_unitHp;
}

unsigned int FragTrap::getUnitEp() const {
	return this->_unitEp;
}

unsigned int FragTrap::getUnitAd() const {
	return this->_unitAd;
}
