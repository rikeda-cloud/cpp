#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wronganimal) {
	*this = wronganimal;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& wronganimal) {
	if (this != &wronganimal)
		this->type = wronganimal.type;
	return *this;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal WrongAnimal WrongAnimal" << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return type;
}
