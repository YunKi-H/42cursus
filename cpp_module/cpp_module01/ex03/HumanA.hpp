#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
private:
	std::string name;
	Weapon& weapon;
public:
	void attack() const;
	void setWeapon(Weapon& weapon);
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
};

#endif
