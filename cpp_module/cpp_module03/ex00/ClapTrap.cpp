#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("a ClapTrap"), _hp(10), _ep(10), _ad(0) {
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hp(10), _ep(10), _ad(0) {
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap) {
	*this = clapTrap;
}

ClapTrap::~ClapTrap() {
}

ClapTrap& ClapTrap::operator=(const ClapTrap &rhs) {

}

void ClapTrap::attack(const std::string& target) {

}

void ClapTrap::takeDamage(unsigned int amount) {

}

void ClapTrap::beRepaired(unsigned int amount) {

}
