#ifndef CURE_HPP
# define CURE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria {
private:
	static const std::string _className;
	static const std::string _materiaName;

public:
	Cure();
	Cure(const Cure &cure);
	virtual ~Cure();

	Cure &operator=(const Cure &rhs);

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
