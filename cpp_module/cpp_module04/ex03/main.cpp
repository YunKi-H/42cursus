#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	// std::cout << "1\n";
	ICharacter* me = new Character("me");
	// std::cout << "2\n";
	AMateria* tmp;
	// std::cout << "3\n";
	tmp = src->createMateria("ice");
	// std::cout << "4\n";
	me->equip(tmp);
	// std::cout << "5\n";
	tmp = src->createMateria("cure");
	// std::cout << "6\n";
	me->equip(tmp);
	// std::cout << "7\n";
	ICharacter* bob = new Character("bob");
	// std::cout << "8\n";
	me->use(0, *bob);
	// std::cout << "9\n";
	me->use(1, *bob);
	// std::cout << "10\n";
	delete bob;
	delete me;
	delete src;
	system("leaks amateria");
	return 0;
}
