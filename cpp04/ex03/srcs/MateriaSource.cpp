#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < MateriaSource::SLOT_CAPACITY; i++)
		slot_[i] = NULL;
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& materiasource) {
	*slot_ = *materiasource.slot_;
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < SLOT_CAPACITY; i++) {
		if (slot_[i] != NULL)
			delete slot_[i];
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& materiasource) {
	if (this != &materiasource) {
		*this->slot_ = *materiasource.slot_;
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria* amateria) {
	for (int i = 0; i < MateriaSource::SLOT_CAPACITY; i++) {
		if (slot_[i] == NULL) {
			slot_[i] = amateria;
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < MateriaSource::SLOT_CAPACITY; i++) {
		if (slot_[i] != NULL && slot_[i]->getType() == type)
			return slot_[i]->clone();
	}
	return NULL;
}
