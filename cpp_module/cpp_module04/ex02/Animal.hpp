#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
	static const std::string _className;
	std::string _type;
public:
	Animal();
	Animal(const Animal &animal);
	virtual ~Animal();

	Animal &operator=(const Animal &rhs);

	virtual void makeSound() const = 0;

	std::string getType() const;
	void setType(const std::string &type);
};

#endif
