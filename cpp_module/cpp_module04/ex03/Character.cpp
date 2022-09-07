#include "Character.hpp"

const std::string _className = "Character";

Character::Character() : _name("noName") {
	for (int i = 0; i < this->_materiaSlotCap; i++) {
		this->_materias[i] = NULL;
	}
	std::cout << this->_className
	<< " [" << this->getName()
	<< "] is generated!" << std::endl;
}

Character::Character(const std::string &name) : _name(name) {
	for (int i = 0; i < this->_materiaSlotCap; i++) {
		this->_materias[i] = NULL;
	}
	std::cout << this->_className
	<< " [" << this->getName()
	<< "] is generated!" << std::endl;
}

Character::Character(const Character &character) {
	*this = character;
	std::cout << this->_className
	<< " [" << this->getName()
	<< "] is generated!" << std::endl;
}

Character::~Character() {
	for (int i = 0; i < this->_materiaSlotCap; i++) {
		if (this->_materias[i] != NULL) {
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
	}
	std::cout << this->_className
	<< " [" << this->getName()
	<< "] is destructer!" << std::endl;
}

Character &Character::operator=(const Character &rhs) {
	for (int i = 0; i < this->_materiaSlotCap; i++) {
		if (this->_materias[i] != NULL) {
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
		if (rhs.getMateria(i) != NULL) {
			this->_materias[i] = rhs.getMateria(i)->clone();
		}
	}
	this->_name = rhs.getName();
	return *this;
}

const AMateria *Character::getMateria(const int idx) const {
	return this->_materias[idx];
}

std::string const &Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < this->_materiaSlotCap; i++) {
		if (this->_materias[i] == NULL) {
			this->_materias[i] = m;
			std::cout << this->_className
			<< " [" << this->getName()
			<< "] equip [" << m->getType() << "] at slot "
			<< i << std::endl;
			return;
		}
	}
	std::cout << this->_className
	<< " [" << this->getName()
	<< "] have no space on Skill Slot!" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 && idx >= this->_materiaSlotCap) {
		std::cout << this->_className
		<< " [" << this->getName()
		<< "] invalid slot Index!" << std::endl;
		return;
	}
	if (this->_materias[idx] != NULL) {
		std::cout << this->_className
		<< " [" << this->getName()
		<< "] unequip [" << this->_materias[idx]->getType()
		<< "]" << std::endl;
		this->_materias[idx] = NULL;
	} else {
		std::cout << this->_className
		<< " [" << this->getName()
		<< "] slot " << idx << " is already empty!" << std::endl;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 && idx >= this->_materiaSlotCap) {
		std::cout << this->_className
		<< " [" << this->getName()
		<< "] invalid slot Index!" << std::endl;
		return;
	}
	if (this->_materias[idx] != NULL) {
		std::cout << this->_className
		<< " [" << this->getName()
		<< "] use " << this->_materias[idx]->getType()
		<< " to [" << target.getName() << "]" << std::endl;
		this->_materias[idx]->use(target);
	} else {
		std::cout << this->_className
		<< " [" << this->getName()
		<< "] slot " << idx << " is empty!" << std::endl;
	}
}
