#include "Brain.hpp"
#include "Colors.hpp"
#include <iostream>

Brain::Brain(void) {
	std::cout << Colors::WHITE << "Brain constructor called" << Colors::RESET << std::endl;
}

Brain::Brain(const Brain& brain) {
	for (size_t i = 0; i < IDEAS_MAX; i++)
		this->ideas[i] = brain.ideas[i];
	std::cout << Colors::WHITE << "Brain copy constructor called" << Colors::RESET << std::endl;
}

Brain::~Brain(void) {
	std::cout << Colors::WHITE << "Brain destructor called" << Colors::RESET << std::endl;
}

Brain&	Brain::operator=(const Brain& brain) {
	if (this != &brain) {
		for (size_t i = 0; i < IDEAS_MAX; i++)
			this->ideas[i] = brain.ideas[i];
	}
	std::cout << Colors::WHITE << "Brain assignment operator called" << Colors::RESET << std::endl;
	return *this;
}

const std::string*	Brain::getIdea(size_t idx) const {
	if (idx < IDEAS_MAX)
		return &this->ideas[idx];
	else {
		std::cerr << "index accepts 0 to 99" << std::endl;
		return NULL;
	}
}

void	Brain::setIdea(size_t idx, const std::string& new_idea) {
	if (idx < IDEAS_MAX)
		this->ideas[idx] = new_idea;
	else
		std::cerr << "index accepts 0 to 99" << std::endl;
}
