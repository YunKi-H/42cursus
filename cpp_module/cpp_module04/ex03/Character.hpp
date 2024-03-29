#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter {
private:
	static const int _materiaSlotCap = 4;

	std::string _name;
	AMateria *_materias[Character::_materiaSlotCap];
public:
	Character();
	Character(const std::string &name);
	Character(const Character &character);
	virtual ~Character();

	Character &operator=(const Character &rhs);

	const AMateria *getMateria(const int idx) const;
	const std::string &getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif
