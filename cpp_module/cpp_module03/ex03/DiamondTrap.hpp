#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
protected:
	std::string _name;

	static const std::string _unitType;
	static const unsigned int _unitHp = FragTrap::_unitHp;
	static const unsigned int _unitEp = ScavTrap::_unitEp;
	static const unsigned int _unitAd = FragTrap::_unitAd;
public:
	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& diamondTrap);
	virtual ~DiamondTrap();

	DiamondTrap &operator=(const DiamondTrap &rhs);

	std::string getName() const;
	void setName(std::string name);

	void attack(const std::string& target);
	void whoAmI() const;

	virtual std::string getUnitType() const;
	virtual unsigned int getUnitHp() const;
	virtual unsigned int getUnitEp() const;
	virtual unsigned int getUnitAd() const;
};

#endif
