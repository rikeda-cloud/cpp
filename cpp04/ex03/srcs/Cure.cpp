#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure") {
	// std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& cure) : AMateria(cure.type_) {
	// std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure(void) {
	// std::cout << "Cure destructor called" << std::endl;
}

Cure&	Cure::operator=(const Cure& cure) {
	if (this != &cure)
		AMateria::operator=(cure);
	return *this;
}

AMateria*	Cure::clone(void) const {
	return new Cure(*this);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
