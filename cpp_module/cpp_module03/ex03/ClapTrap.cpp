#include "ClapTrap.hpp"

const std::string ClapTrap::_unitType = "ClapTrap";

ClapTrap::ClapTrap() : _name("a ClapTrap"), _hp(_unitHp), _ep(_unitEp), _ad(_unitAd) {
	std::cout << this->getUnitType() << " [" << this->getName() << "] generated!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hp(10), _ep(10), _ad(0) {
	std::cout << this->getUnitType() << " [" << this->getName() << "] generated!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap) {
	*this = clapTrap;
	std::cout << this->getUnitType() << " [" << this->getName() << "] generated!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << this->getUnitType() << " [" << this->getName() << "] destroyed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &rhs) {
	this->_name = rhs.getName();
	this->_hp = rhs.getHp();
	this->_ep = rhs.getEp();
	this->_ad = rhs.getAd();
	return *this;
}

void ClapTrap::announce() const {
	std::cout << this->getUnitType() << " [" << this->getName() << "]" << std::endl;
	std::cout << "Hit Point     :" << this->_hp << std::endl;
	std::cout << "Energy Point  :" << this->_ep << std::endl;
	std::cout << "Attack Damage :" << this->_ad << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (!this->_hp || !this->_ep) {
		std::cout << this->getUnitType() << " ["
		<< this->getName()
		<< "] can`t move anymore!" << std::endl;
		return;
	}
	std::cout << this->getUnitType() << " ["
	<< this->getName()
	<< "] attacks ["
	<< target
	<< "], causing "
	<< this->_ad
	<< " points of damage!" << std::endl;
	this->_ep -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << this->getUnitType() << " ["
	<< this->getName()
	<< "] takes "
	<< amount
	<< " points of damage!" << std::endl;
	this->_hp -= (this->_hp > amount ? amount : this->_hp);
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!this->_hp || !this->_ep) {
		std::cout << this->getUnitType() << " ["
		<< this->getName()
		<< "] can`t move anymore!" << std::endl;
		return;
	}
	std::cout << this->getUnitType() << " ["
	<< this->getName()
	<< "] repairs "
	<< amount
	<< " points of HP!" << std::endl;
	this->_hp += amount;
	this->_ep -= 1;
}

std::string ClapTrap::getUnitType() const {
	return this->_unitType;
}

unsigned int ClapTrap::getUnitHp() const {
	return this->_unitHp;
}

unsigned int ClapTrap::getUnitEp() const {
	return this->_unitEp;
}

unsigned int ClapTrap::getUnitAd() const {
	return this->_unitAd;
}

std::string ClapTrap::getName() const {
	return this->_name;
}

unsigned int ClapTrap::getHp() const {
	return this->_hp;
}

unsigned int ClapTrap::getEp() const {
	return this->_ep;
}

unsigned int ClapTrap::getAd() const {
	return this->_ad;
}

void ClapTrap::setName(std::string name) {
	this->_name = name;
}

void ClapTrap::setHp(unsigned int hitPoint) {
	this->_hp = hitPoint;
}

void ClapTrap::setEp(unsigned int energyPoint) {
	this->_ep = energyPoint;
}

void ClapTrap::setAd(unsigned int attackDamage) {
	this->_ad = attackDamage;
}
