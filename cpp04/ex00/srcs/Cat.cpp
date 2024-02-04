#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal() {
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& cat) {
	*this = cat;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& cat) {
	this->type = cat.type;
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "Cat Cat Cat" << std::endl;
}

std::string	Cat::getType(void) const {
	return type;
}
