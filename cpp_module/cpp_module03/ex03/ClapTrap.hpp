#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
protected:
	static const std::string _unitType;
	static const unsigned int _unitHp = 10;
	static const unsigned int _unitEp = 10;
	static const unsigned int _unitAd = 0;

	std::string _name;
	unsigned int _hp;
	unsigned int _ep;
	unsigned int _ad;
public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& clapTrap);
	virtual ~ClapTrap();

	ClapTrap &operator=(const ClapTrap &rhs);

	void announce() const;
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	virtual std::string getUnitType() const;
	virtual unsigned int getUnitHp() const;
	virtual unsigned int getUnitEp() const;
	virtual unsigned int getUnitAd() const;
	virtual std::string getName() const;
	unsigned int getHp() const;
	unsigned int getEp() const;
	unsigned int getAd() const;
	virtual void setName(std::string name);
	void setHp(unsigned int hitPoint);
	void setEp(unsigned int energyPoint);
	void setAd(unsigned int attackDamage);
};

#endif
