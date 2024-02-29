#include "WrongCat.hpp"
#include "Colors.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal() {
	this->type = "WrongCat";
	std::cout << Colors::GREEN << "WrongCat constructor called" << Colors::RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongcat) : WrongAnimal(wrongcat) {
	std::cout << Colors::GREEN << "WrongCat copy constructor called" << Colors::RESET << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << Colors::GREEN << "WrongCat destructor called" << Colors::RESET << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& wrongcat) {
	if (this != &wrongcat)
		this->type = wrongcat.type;
	return *this;
}

void	WrongCat::makeSound(void) const {
	std::cout << Colors::GREEN << "WrongCat WrongCat WrongCat" << Colors::RESET << std::endl;
}
