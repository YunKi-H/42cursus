#include <iostream>
#include "Zombie.hpp"

int main() {
	std::cout << "-----Default Zombie-----" << std::endl;
	Zombie z1 = Zombie();
	std::cout << std::endl;
	std::cout << "------Named Zombie------" << std::endl;
	Zombie z2 = Zombie("Named Zombie");
	std::cout << std::endl;
	std::cout << "------Heap Zombie-------" << std::endl;
	Zombie* z3 = Zombie::newZombie("Heap Zombie");
	std::cout << std::endl;
	std::cout << "------Stack Zombie------" << std::endl;
	Zombie::randomChump("Stack Zombie");
	std::cout << std::endl;
	std::cout << "---Delete Heap Zombie---" << std::endl;
	delete z3;
	std::cout << "------------------------" << std::endl;
	std::cout << std::endl;
}
