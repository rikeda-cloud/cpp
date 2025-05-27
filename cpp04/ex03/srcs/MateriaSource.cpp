#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < MateriaSource::SLOT_CAPACITY; i++)
		slot_[i] = NULL;
	// std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& source) {
	for (int i = 0; i < MateriaSource::SLOT_CAPACITY; i++) {
		if (this->slot_[i] != NULL)
			delete this->slot_[i];
		this->slot_[i] = NULL;
	}
	for (int i = 0; i < MateriaSource::SLOT_CAPACITY; i++) {
		if (source.slot_[i] != NULL)
			this->slot_[i] = source.slot_[i]->clone();
	}
	// std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < MateriaSource::SLOT_CAPACITY; i++) {
		if (slot_[i] != NULL)
			delete slot_[i];
	}
	// std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& source) {
	if (this != &source) {
		for (int i = 0; i < MateriaSource::SLOT_CAPACITY; i++) {
			if (this->slot_[i] != NULL)
				delete this->slot_[i];
			this->slot_[i] = NULL;
		}
		for (int i = 0; i < MateriaSource::SLOT_CAPACITY; i++) {
			if (source.slot_[i] != NULL)
				this->slot_[i] = source.slot_[i]->clone();
		}
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < MateriaSource::SLOT_CAPACITY; i++) {
		if (slot_[i] == NULL) {
			slot_[i] = m;
			return ;
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
