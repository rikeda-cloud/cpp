#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat(void) : Animal() {
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& cat) {
	*this = cat;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void) {
	if (this->brain)
		delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& cat) {
	if (this->brain)
		delete this->brain;
	this->type = cat.type;
	this->brain = cat.brain;
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "Cat Cat Cat" << std::endl;
}

std::string	Cat::getType(void) const {
	return type;
}
