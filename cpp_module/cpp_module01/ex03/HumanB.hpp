#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
	std::string name;
	Weapon* weapon;
public:
	void attack() const;
	void setWeapon(Weapon& weapon);
	HumanB(std::string name);
	HumanB();
	~HumanB();
};

#endif
