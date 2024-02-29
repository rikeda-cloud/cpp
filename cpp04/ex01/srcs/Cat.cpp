#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat(void) : Animal() {
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat) {
	this->brain = new Brain();
	*this->brain = *cat.brain;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void) {
	if (this->brain)
		delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& cat) {
	if (this != &cat) {
		Animal::operator=(cat);
		*this->brain = *cat.brain;
	}
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "Cat Cat Cat" << std::endl;
}

void	Cat::comeUpWithIdea(size_t idx, const std::string& idea) {
	this->brain->setIdea(idx, idea);
}

void	Cat::rememberIdea(size_t idx) const {
	const std::string*	idea = this->brain->getIdea(idx);
	if (idea)
		std::cout << this->type << "[" << idx << "] = " << *idea << std::endl;
}
