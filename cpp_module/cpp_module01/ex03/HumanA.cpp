#include <iostream>
#include "HumanA.hpp"

void HumanA::attack() const {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon& weapon) {
	this->weapon = weapon;
}

HumanA::HumanA(std::string name, Weapon& weapon)
: name(name), weapon(weapon) {
}

HumanA::~HumanA() {
}
