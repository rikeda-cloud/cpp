#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice") {
	// std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& ice) : AMateria(ice.type_) {
	// std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice(void) {
	// std::cout << "Ice destructor called" << std::endl;
}

Ice&	Ice::operator=(const Ice& ice) {
	if (this != &ice)
		AMateria::operator=(ice);
	return *this;
}

AMateria*	Ice::clone(void) const {
	return new Ice(*this);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
