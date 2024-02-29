#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal() {
	this->type = "WrongCat";
	this->brain = new Brain();
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongcat) : WrongAnimal(wrongcat) {
	this->brain = new Brain();
	*this->brain = *wrongcat.brain;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {
	if (this->brain)
		delete this->brain;
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& wrongcat) {
	if (this != &wrongcat) {
		WrongAnimal::operator=(wrongcat);
		*this->brain = *wrongcat.brain;
	}
	return *this;
}

void	WrongCat::makeSound(void) const {
	std::cout << "WrongCat WrongCat WrongCat" << std::endl;
}

void	WrongCat::comeUpWithIdea(size_t idx, const std::string& idea) {
	this->brain->setIdea(idx, idea);
}

void	WrongCat::rememberIdea(size_t idx) const {
	const std::string*	idea = this->brain->getIdea(idx);
	if (idea)
		std::cout << this->type << "[" << idx << "] = " << *idea << std::endl;
}
