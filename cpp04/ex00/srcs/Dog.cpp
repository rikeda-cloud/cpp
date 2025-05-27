#include "Dog.hpp"
#include "Colors.hpp"
#include <iostream>

Dog::Dog(void) : Animal() {
	this->type = "Dog";
	std::cout << Colors::RED << "Dog constructor called" << Colors::RESET << std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog) {
	std::cout << Colors::RED << "Dog copy constructor called" << Colors::RESET << std::endl;
}

Dog::~Dog(void) {
	std::cout << Colors::RED << "Dog destructor called" << Colors::RESET << std::endl;
}

Dog&	Dog::operator=(const Dog& dog) {
	if (this != &dog)
		Animal::operator=(dog);
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << Colors::RED << "Dog Dog Dog" << Colors::RESET << std::endl;
}
