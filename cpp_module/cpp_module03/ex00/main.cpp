#include <iostream>
#include "ClapTrap.hpp"

int main() {
	ClapTrap a("ClapTrapA");
	ClapTrap b("ClapTrapB");
	ClapTrap c(b);

	c.announce();
	c.setName("ClapTrapC");
	c.announce();
	a.announce();
	b.announce();
	a.attack(b.getName());
	b.takeDamage(a.getAd());
	a.takeDamage(5);
	a.beRepaired(3);
	b.attack("A Hard Rock");
	b.takeDamage(b.getHp());
	b.beRepaired(10);
	a.announce();
	b.announce();
	c.announce();
}
