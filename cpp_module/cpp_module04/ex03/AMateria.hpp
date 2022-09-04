#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria {
protected:
	static const std::string _className;
	std::string _type;

public:
	AMateria();
	AMateria(const AMateria &amateria);
	AMateria(std::string const & type);
	virtual ~AMateria();

	AMateria &operator=(const AMateria &rhs);

	std::string const &getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
#endif
