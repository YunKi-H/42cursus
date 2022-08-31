#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
protected:
	static const std::string _unitType;
	static const unsigned int _unitHp = 100;
	static const unsigned int _unitEp = 100;
	static const unsigned int _unitAd = 30;

public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& fragTrap);
	virtual ~FragTrap();

	FragTrap &operator=(const FragTrap &rhs);

	virtual void attack(const std::string& target);
	void highFivesGuys() const;

	virtual std::string getUnitType() const;
	virtual unsigned int getUnitHp() const;
	virtual unsigned int getUnitEp() const;
	virtual unsigned int getUnitAd() const;
};

#endif
