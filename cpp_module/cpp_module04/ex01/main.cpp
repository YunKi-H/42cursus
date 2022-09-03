#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	Cat* a = new Cat();
	Cat* b = new Cat(*a);
	for (int i = 0; i < 3; i++) {
		b->getBrain()->setIdea(i, "new Idea");
	}
	std::cout << "-- a Brain --" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << a->getBrain()->getIdea(i) << std::endl;
	}
	std::cout << "-- b Brain --" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << b->getBrain()->getIdea(i) << std::endl;
	}
	std::cout << std::endl;

	std::cout << "delete j, i" << std::endl;
	delete j;//should not create a leak
	delete i;
	std::cout << std::endl;
	std::cout << "delete a, b" << std::endl;
	delete a;
	delete b;
	std::cout << std::endl;
	system("leaks brain");
// ...
	return 0;
}
