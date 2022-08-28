#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
protected:
	static const std::string _unitType;
	static const unsigned int _unitHp = 100;
	static const unsigned int _unitEp = 50;
	static const unsigned int _unitAd = 20;

public:
	ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap& scavTrap);
	virtual ~ScavTrap();

	ScavTrap &operator=(const ScavTrap &rhs);

	virtual void attack(const std::string& target);
	void guardGate() const;
};

#endif
