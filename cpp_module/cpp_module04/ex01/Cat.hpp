#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
	static const std::string _className;
	Brain *_brain;
public:
	Cat();
	Cat(const Cat &cat);
	virtual ~Cat();

	Cat &operator=(const Cat &rhs);

	virtual void makeSound() const;

	Brain *getBrain() const;
};

#endif
