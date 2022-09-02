#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
private:
	static const std::string _className;
public:
	Cat();
	Cat(const Cat &cat);
	virtual ~Cat();

	Cat &operator=(const Cat &rhs);

	virtual void makeSound() const;
};

#endif
