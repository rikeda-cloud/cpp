#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal() {
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& dog) {
	*this = dog;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& dog) {
	this->type = dog.type;
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "Dog Dog Dog" << std::endl;
}

std::string	Dog::getType(void) const {
	return type;
}
