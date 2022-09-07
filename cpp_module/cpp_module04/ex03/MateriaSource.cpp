#include "MateriaSource.hpp"

const std::string _className = "MateriaSource";

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
		this->_materias[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
	for (int i = 0; i < this->_materiaSlotCap; i++) {
		delete this->_materias[i];
		this->_materias[i] = rhs._materias[i];
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < this->_materiaSlotCap; i++) {
		if (this->_materias[i] != NULL) {
			this->_materias[i] = materia;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < this->_materiaSlotCap; i++) {
		if (this->_materias[i] != NULL && this->_materias[i]->getType() == type) {
			return this->_materias[i]->clone();
		}
	}
	return NULL;
}
