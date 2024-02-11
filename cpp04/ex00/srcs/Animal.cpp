#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : type("Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& animal) {
	*this = animal;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& animal) {
	if (this != &animal)
		this->type = animal.type;
	return *this;
}

void	Animal::makeSound(void) const {
	std::cout << "Animal Animal Animal" << std::endl;
}

std::string	Animal::getType(void) const {
	return type;
}
