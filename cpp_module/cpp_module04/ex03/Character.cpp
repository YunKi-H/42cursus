#include "Character.hpp"

Character::Character() : _name("noName") {
	for (int i = 0; i < this->_materiaSlotCap; i++) {
		this->_materias[i] = NULL;
	}
}

Character::Character(const std::string &name) : _name(name) {
	for (int i = 0; i < this->_materiaSlotCap; i++) {
		this->_materias[i] = NULL;
	}
}

Character::Character(const Character &character) {
	*this = character;
}

Character::~Character() {
	for (int i = 0; i < this->_materiaSlotCap; i++) {
		delete this->_materias[i];
	}
}

Character &Character::operator=(const Character &rhs) {
	this->_name = rhs.getName();
	for (int i = 0; i < this->_materiaSlotCap; i++) {
		delete this->_materias[i];
		if (rhs.getMateria(i) != NULL) {
			this->_materias[i] = rhs.getMateria(i)->clone();
		} else {
			this->_materias[i] = NULL;
		}
	}
	return *this;
}

const AMateria *Character::getMateria(const int idx) const {
	if (idx >= 0 && idx < this->_materiaSlotCap) {
		return this->_materias[idx];
	}
	return NULL;
}

const std::string &Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < this->_materiaSlotCap; i++) {
		if (this->_materias[i] == NULL) {
			this->_materias[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < this->_materiaSlotCap) {
		this->_materias[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target) {
	std::cout << this->_name << " ";
	if (idx >= 0 && idx < this->_materiaSlotCap) {
		this->_materias[idx]->use(target);
	}
}
