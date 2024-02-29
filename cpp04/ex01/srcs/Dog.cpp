#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog(void) : Animal() {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog) {
	this->brain = new Brain();
	*this->brain = *dog.brain;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void) {
	if (this->brain)
		delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& dog) {
	if (this != &dog) {
		Animal::operator=(dog);
		*this->brain = *dog.brain;
	}
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "Dog Dog Dog" << std::endl;
}

void	Dog::comeUpWithIdea(size_t idx, const std::string& idea) {
	this->brain->setIdea(idx, idea);
}

void	Dog::rememberIdea(size_t idx) const {
	const std::string*	idea = this->brain->getIdea(idx);
	if (idea)
		std::cout << this->type << "[" << idx << "] = " << *idea << std::endl;
}
