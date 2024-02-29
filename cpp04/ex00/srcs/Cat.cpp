#include "Cat.hpp"
#include "Colors.hpp"
#include <iostream>

Cat::Cat(void) : Animal() {
	this->type = "Cat";
	std::cout << Colors::YELLOW << "Cat constructor called" << Colors::RESET << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat) {
	std::cout << Colors::YELLOW << "Cat copy constructor called" << Colors::RESET << std::endl;
}

Cat::~Cat(void) {
	std::cout << Colors::YELLOW << "Cat destructor called" << Colors::RESET << std::endl;
}

Cat&	Cat::operator=(const Cat& cat) {
	if (this != &cat)
		Animal::operator=(cat);
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << Colors::YELLOW << "Cat Cat Cat" << Colors::RESET << std::endl;
}
