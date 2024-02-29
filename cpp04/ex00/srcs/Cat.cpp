#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal() {
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& cat) {
	if (this != &cat)
		Animal::operator=(cat);
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "Cat Cat Cat" << std::endl;
}
