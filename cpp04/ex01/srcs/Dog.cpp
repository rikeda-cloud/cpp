#include "Dog.hpp"
#include "Brain.hpp"
#include "Colors.hpp"
#include <iostream>

Dog::Dog(void) : Animal() {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << Colors::RED << "Dog constructor called" << Colors::RESET << std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog) {
	this->brain = new Brain(*dog.brain);
	std::cout << Colors::RED << "Dog copy constructor called" << Colors::RESET << std::endl;
}

Dog::~Dog(void) {
	if (this->brain)
		delete this->brain;
	std::cout << Colors::RED << "Dog destructor called" << Colors::RESET << std::endl;
}

Dog&	Dog::operator=(const Dog& dog) {
	if (this != &dog) {
		Animal::operator=(dog);
		*this->brain = *dog.brain;
	}
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << Colors::RED << "Dog Dog Dog" << Colors::RESET << std::endl;
}

void	Dog::comeUpWithIdea(size_t idx, const std::string& idea) {
	this->brain->setIdea(idx, idea);
}

void	Dog::rememberIdea(size_t idx) const {
	const std::string*	idea = this->brain->getIdea(idx);
	if (idea)
		std::cout << this->type << "[" << idx << "] = " << *idea << std::endl;
}
