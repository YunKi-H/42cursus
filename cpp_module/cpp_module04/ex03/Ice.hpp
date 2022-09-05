#ifndef ICE_HPP
# define ICE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria {
private:
	static const std::string _className;
	static const std::string _materiaName;

public:
	Ice();
	Ice(const Ice &ice);
	virtual ~Ice();

	Ice &operator=(const Ice &rhs);

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
