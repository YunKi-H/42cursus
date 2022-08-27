#include "ScavTrap.hpp"

const std::string ScavTrap::_unitType = "ScavTrap";

ScavTrap::ScavTrap() : _name("a ScavTrap"), _hp(ScavTrap::_unitHp), _ep(ScavTrap::_unitEp), _ad(ScavTrap::_unitAd) {
	std::cout << this->_unitType << " [" << this->_name << "] generated!" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : _name(name), _hp(ScavTrap::_unitHp), _ep(ScavTrap::_unitEp), _ad(ScavTrap::_unitAd) {
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

void ScavTrap::announce() const {
	std::cout << this->_unitType << " [" << this->_name << "]" << std::endl;
	std::cout << "Hit Point     :" << this->_hp << std::endl;
	std::cout << "Energy Point  :" << this->_ep << std::endl;
	std::cout << "Attack Damage :" << this->_ad << std::endl;
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
	<< "] attacks ["
	<< target
	<< "], causing "
	<< this->_ad
	<< " points of damage!" << std::endl;
	this->_ep -= 1;
}

void ScavTrap::takeDamage(unsigned int amount) {
	std::cout << this->_unitType << " ["
	<< this->_name
	<< "] takes "
	<< amount
	<< " points of damage!" << std::endl;
	this->_hp -= (this->_hp > amount ? amount : this->_hp);
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (!this->_hp || !this->_ep) {
		std::cout << this->_unitType << " ["
		<< this->_name
		<< "] can`t move anymore!" << std::endl;
		return;
	}
	std::cout << this->_unitType << " ["
	<< this->_name
	<< "] repairs "
	<< amount
	<< " points of HP!" << std::endl;
	this->_hp += amount;
}

std::string ScavTrap::getName() const {
	return this->_name;
}

unsigned int ScavTrap::getHp() const {
	return this->_hp;
}

unsigned int ScavTrap::getEp() const {
	return this->_ep;
}

unsigned int ScavTrap::getAd() const {
	return this->_ad;
}

void ScavTrap::setName(std::string name) {
	this->_name = name;
}

void ScavTrap::setHp(unsigned int hitPoint) {
	this->_hp = hitPoint;
}

void ScavTrap::setEp(unsigned int energyPoint) {
	this->_ep = energyPoint;
}

void ScavTrap::setAd(unsigned int attackDamage) {
	this->_ad = attackDamage;
}

void ScavTrap::guardGate() const {
	std::cout << this->_unitType << " [" << this->_name
	<< "] is now on Gatekeeper Mode!" << std::endl;
}
