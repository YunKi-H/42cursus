#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
	std::string _name;
	unsigned int _hp;
	unsigned int _ep;
	unsigned int _ad;
public:
	ScavTrap();
	~ScavTrap();
};

#endif
