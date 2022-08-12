#include <iostream>
#include "Zombie.hpp"

int main() {
	std::cout << "-----Default Zombie-----\n" << std::endl;
	Zombie z1 = Zombie();
	z1.announce();

	std::cout << "------Named Zombie------\n" << std::endl;
	Zombie z2 = Zombie("Named Zombie");

	std::cout << "------Heap Zombie-------\n" << std::endl;
	Zombie* z3 = Zombie::newZombie("Heap Zombie");

	std::cout << "------Stack Zombie------\n" << std::endl;
	Zombie::randomChump("Stack Zombie");

	std::cout << "---Delete Heap Zombie---\n" << std::endl;
	delete z3;
	std::cout << "------------------------\n" << std::endl;

}
