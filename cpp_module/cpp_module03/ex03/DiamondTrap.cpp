#include "DiamondTrap.hpp"

const std::string DiamondTrap::_unitType = "DiamondTrap";

DiamondTrap::DiamondTrap() :
ClapTrap("a " + this->getUnitType() + "_clap_name") {
	this->_name = "a DiamondTrap";
	this->_hp = this->_unitHp;
	this->_ep = this->_unitEp;
	this->_ad = this->_unitAd;
	std::cout << this->getUnitType() << " [" << this->_name << "] generated!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name") {
	this->_name = name;
	this->_hp = this->_unitHp;
	this->_ep = this->_unitEp;
	this->_ad = this->_unitAd;
	std::cout << this->getUnitType() << " [" << this->_name << "] generated!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) {
	*this = diamondTrap;
	ClapTrap::_name = this->_name + "_clap_name";
	std::cout << this->getUnitType() << " [" << this->_name << "] generated!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << this->getUnitType() << " [" << this->_name << "] destroyed!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &rhs) {
	this->_name = rhs.getName();
	this->_hp = rhs.getHp();
	this->_ep = rhs.getEp();
	this->_ad = rhs.getAd();
	return *this;
}

std::string DiamondTrap::getName() const {
	return this->_name;
}

void DiamondTrap::setName(std::string name) {
	this->_name = name;
	ClapTrap::_name = this->_name + "_clap_name";
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const {
	std::cout << "I am [" << this->_name
	<< "] and I also [" << ClapTrap::_name
	<< "]"<< std::endl;
}

std::string DiamondTrap::getUnitType() const {
	return this->_unitType;
}

unsigned int DiamondTrap::getUnitHp() const {
	return this->_unitHp;
}

unsigned int DiamondTrap::getUnitEp() const {
	return this->_unitEp;
}

unsigned int DiamondTrap::getUnitAd() const {
	return this->_unitAd;
}
