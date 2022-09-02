#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
private:
	static const std::string _className;
public:
	WrongCat();
	WrongCat(const WrongCat &wrongCat);
	virtual ~WrongCat();

	WrongCat &operator=(const WrongCat &rhs);

	void makeSound() const;
};

#endif
