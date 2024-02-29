#include "Animal.hpp"
#include "Colors.hpp"
#include <iostream>

Animal::Animal(void) : type("Animal") {
	std::cout << Colors::BLUE << "Animal constructor called" << Colors::RESET << std::endl;
}

Animal::Animal(const Animal& animal) : type(animal.type) {
	std::cout << Colors::BLUE << "Animal copy constructor called" << Colors::RESET << std::endl;
}

Animal::~Animal(void) {
	std::cout << Colors::BLUE << "Animal destructor called" << Colors::RESET << std::endl;
}

Animal&	Animal::operator=(const Animal& animal) {
	if (this != &animal)
		this->type = animal.type;
	return *this;
}

std::string	Animal::getType(void) const {
	return type;
}
