#include <iostream>
#include "Zombie.hpp"

int main() {
	std::cout << "-----Default Zombie-----" << std::endl;
	Zombie z1 = Zombie();
	z1.announce();

	std::cout << "\n------Named Zombie------" << std::endl;
	Zombie z2 = Zombie("Named Zombie");

	std::cout << "\n------Zombie Horde------" << std::endl;
	Zombie* z3 = Zombie::zombieHorde(10, "zombie");

	std::cout << "\n---Delete Zombie Horde--" << std::endl;
	delete[] z3;
	std::cout << "\n------------------------" << std::endl;
}
