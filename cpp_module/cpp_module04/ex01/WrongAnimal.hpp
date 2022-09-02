#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
	static const std::string _className;
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &wrongAnimal);
	virtual ~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &rhs);

	void makeSound() const;

	std::string getType() const;
	void setType(const std::string &type);
};

#endif
