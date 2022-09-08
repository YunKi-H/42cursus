#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < this->_materiaSlotCap; i++) {
		this->_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) {
	*this = materiaSource;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < this->_materiaSlotCap; i++) {
		delete this->_materias[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
	for (int i = 0; i < this->_materiaSlotCap; i++) {
		delete this->_materias[i];
		if (rhs.getMateria(i) != NULL) {
			this->_materias[i] = rhs.getMateria(i)->clone();
		} else {
			this->_materias[i] = NULL;
		}
	}
	return *this;
}

const AMateria *MateriaSource::getMateria(const int idx) const {
	if (idx >= 0 && idx < this->_materiaSlotCap) {
		return this->_materias[idx];
	}
	return NULL;
}

void MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < this->_materiaSlotCap; i++) {
		if (this->_materias[i] == NULL) {
			this->_materias[i] = materia;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < this->_materiaSlotCap; i++) {
		if (this->_materias[i]->getType() == type) {
			return this->_materias[i]->clone();
		}
	}
	return NULL;
}
