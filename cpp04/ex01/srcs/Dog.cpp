#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal() {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& dog) {
	*this = dog;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void) {
	if (this->brain)
		delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& dog) {
	delete this->brain;
	this->type = dog.type;
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "Dog Dog Dog" << std::endl;
}

std::string	Dog::getType(void) const {
	return type;
}
