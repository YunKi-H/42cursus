#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	static const std::string _className;
	Brain *_brain;
public:
	Dog();
	Dog(const Dog &dog);
	virtual ~Dog();

	Dog &operator=(const Dog &rhs);

	virtual void makeSound() const;
};

#endif
