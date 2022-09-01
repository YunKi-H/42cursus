#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
	std::string _type;
public:
	Animal(/* args */);
	Animal(const Animal &animal);
	virtual ~Animal();

	Animal &operator=(const Animal &rhs);

	virtual void makeSound() const;
};

#endif
