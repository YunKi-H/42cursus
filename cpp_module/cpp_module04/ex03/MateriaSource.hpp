#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
	static const int _materiaSlotCap = 4;

	AMateria *_materias[MateriaSource::_materiaSlotCap];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &materiaSource);
	virtual ~MateriaSource();

	MateriaSource &operator=(const MateriaSource &rhs);

	const AMateria *getMateria(const int idx) const;
	void learnMateria(AMateria *materia);
	AMateria *createMateria(std::string const &type);
};

#endif
