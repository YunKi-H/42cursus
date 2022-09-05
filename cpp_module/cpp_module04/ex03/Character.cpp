#include "Character.hpp"

const std::string _className = "Character";

Character::Character() {

}
Character::Character(const std::string &name) {

}
Character::Character(const Character &character) {

}
Character::~Character() {

}

Character &Character::operator=(const Character &rhs) {

}

std::string const &Character::getName() const {

}
void Character::equip(AMateria* m) {

}
void Character::unequip(int idx) {

}
void Character::use(int idx, ICharacter &target) {

}
