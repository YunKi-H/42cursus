#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
	this->announce();
}

Zombie::Zombie() {
	this->name = "A Zombie";
}

Zombie::~Zombie() {
	std::cout << this->name
		<< " Destroyed"
		<< std::endl;
}

void Zombie::announce() const {
	std::cout << this->name
		<< ": BraiiiiiiinnnzzzZ..."
		<< std::endl;
}
