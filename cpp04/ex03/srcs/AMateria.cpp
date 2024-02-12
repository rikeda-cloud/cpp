#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(std::string const& type) : type_(type){
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::~AMateria(void) {
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& amateria) {
	if (this != &amateria)
		this->type_ = amateria.type_;
	return *this;
}

std::string	const&	AMateria::getType(void) const {
	return type_;
}

void	AMateria::use(ICharacter& target) {
	std::cout << "Can ABC Materia use ???. name = " << target.getName() << std::endl;
}
