#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
private:
	std::string _name;
	unsigned int _hp;
	unsigned int _ep;
	unsigned int _ad;
public:
	ClapTrap();
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap& clapTrap);
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &rhs);

	void announce() const;
	void attack(const std::string& target);
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
};

#endif
