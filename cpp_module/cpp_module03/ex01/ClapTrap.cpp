#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("a ClapTrap"), _hp(10), _ep(10), _ad(0) {
	std::cout << "ClapTrap [" << this->_name << "] generated!" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hp(10), _ep(10), _ad(0) {
	std::cout << "ClapTrap [" << this->_name << "] generated!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap) {
	*this = clapTrap;
	std::cout << "ClapTrap [" << this->_name << "] generated!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap [" << this->_name << "] destroyed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &rhs) {
	this->_name = rhs.getName();
	this->_hp = rhs.getHp();
	this->_ep = rhs.getEp();
	this->_ad = rhs.getAd();
	return *this;
}

void ClapTrap::announce() const {
	std::cout << "ClapTrap [" << this->_name << "]" << std::endl;
	std::cout << "Hit Point     :" << this->_hp << std::endl;
	std::cout << "Energy Point  :" << this->_ep << std::endl;
	std::cout << "Attack Damage :" << this->_ad << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (!this->_hp || !this->_ep) {
		std::cout << "ClapTrap ["
		<< this->_name
		<< "] can`t move anymore!" << std::endl;
		return;
	}
	std::cout << "ClapTrap ["
	<< this->_name
	<< "] attacks ["
	<< target
	<< "], causing "
	<< this->_ad
	<< " points of damage!" << std::endl;
	this->_ep -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap ["
	<< this->_name
	<< "] takes "
	<< amount
	<< " points of damage!" << std::endl;
	this->_hp -= (this->_hp > amount ? amount : this->_hp);
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!this->_hp || !this->_ep) {
		std::cout << "ClapTrap ["
		<< this->_name
		<< "] can`t move anymore!" << std::endl;
		return;
	}
	std::cout << "ClapTrap ["
	<< this->_name
	<< "] repairs "
	<< amount
	<< " points of HP!" << std::endl;
	this->_hp += amount;
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
