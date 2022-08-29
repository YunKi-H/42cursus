#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	FragTrap a("FragTrapA");
	FragTrap b("FragTrapB");
	FragTrap c(b);

	c.announce();
	c.setName("FragTrapC");
	c.announce();
	a.announce();
	b.announce();
	std::cout << std::endl;
	a.attack(b.getName());
	b.takeDamage(a.getAd());
	b.announce();
	a.takeDamage(5);
	a.beRepaired(3);
	a.announce();
	std::cout << std::endl;
	b.attack("A Hard Rock");
	b.takeDamage(b.getHp());
	b.beRepaired(10);
	std::cout << std::endl;
	a.announce();
	b.announce();
	c.announce();
	c.highFivesGuys();

	// ScavTrap a("ScavTrapA");
	// ScavTrap b("ScavTrapB");
	// ScavTrap c(b);

	// c.announce();
	// c.setName("ScavTrapC");
	// c.announce();
	// a.announce();
	// b.announce();
	// std::cout << std::endl;
	// a.attack(b.getName());
	// b.takeDamage(a.getAd());
	// b.announce();
	// a.takeDamage(5);
	// a.beRepaired(3);
	// a.announce();
	// std::cout << std::endl;
	// b.attack("A Hard Rock");
	// b.takeDamage(b.getHp());
	// b.beRepaired(10);
	// std::cout << std::endl;
	// a.announce();
	// b.announce();
	// c.announce();

	// ClapTrap a("ClapTrapA");
	// ClapTrap b("ClapTrapB");
	// ClapTrap c(b);

	// c.announce();
	// c.setName("ClapTrapC");
	// c.announce();
	// a.announce();
	// b.announce();
	// a.attack(b.getName());
	// b.takeDamage(a.getAd());
	// a.takeDamage(5);
	// a.beRepaired(3);
	// b.attack("A Hard Rock");
	// b.takeDamage(b.getHp());
	// b.beRepaired(10);
	// a.announce();
	// b.announce();
	// c.announce();
}
