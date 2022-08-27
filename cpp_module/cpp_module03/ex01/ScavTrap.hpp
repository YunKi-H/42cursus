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

	std::string _name;
	unsigned int _hp;
	unsigned int _ep;
	unsigned int _ad;
public:
	ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap& scavTrap);
	virtual ~ScavTrap();

	ScavTrap &operator=(const ScavTrap &rhs);

	void announce() const;
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName() const;
	unsigned int getHp() const;
	unsigned int getEp() const;
	unsigned int getAd() const;
	void setName(std::string name);
	void setHp(unsigned int hitPoint);
	void setEp(unsigned int energyPoint);
	void setAd(unsigned int attackDamage);
	void guardGate() const;
};

#endif
