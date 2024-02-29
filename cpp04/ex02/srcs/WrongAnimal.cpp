#include "WrongAnimal.hpp"
#include "Colors.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
	std::cout << Colors::MAGENTA << "WrongAnimal constructor called" << Colors::RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wronganimal) : type(wronganimal.type) {
	std::cout << Colors::MAGENTA << "WrongAnimal copy constructor called" << Colors::RESET << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << Colors::MAGENTA << "WrongAnimal destructor called" << Colors::RESET << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& wronganimal) {
	if (this != &wronganimal)
		this->type = wronganimal.type;
	return *this;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << Colors::MAGENTA << "WrongAnimal WrongAnimal WrongAnimal" << Colors::RESET << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return type;
}
