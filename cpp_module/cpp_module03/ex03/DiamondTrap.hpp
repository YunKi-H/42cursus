#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
protected:
	static const std::string _unitType;
	static const unsigned int _unitHp = FragTrap::_unitHp;
	static const unsigned int _unitEp = ScavTrap::_unitEp;
	static const unsigned int _unitAd = FragTrap::_unitAd;

public:
	DiamondTrap();
	DiamondTrap(const std::string name);
	DiamondTrap(const DiamondTrap& diamondTrap);
	virtual ~DiamondTrap();

	DiamondTrap &operator=(const DiamondTrap &rhs);

	void attack(const std::string& target);
	void whoAmI() const;
};

#endif
