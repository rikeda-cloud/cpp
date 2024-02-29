#include "Brain.hpp"
#include <iostream>

Brain::Brain(void) {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& brain) {
	*this = brain;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& brain) {
	std::cout << "Brain assignment operator called" << std::endl;
	for (size_t i = 0; i < IDEAS_MAX; i++)
		this->ideas[i] = brain.ideas[i];
	return *this;
}

const std::string*	Brain::getIdea(size_t idx) const {
	if (idx < IDEAS_MAX)
		return &this->ideas[idx];
	return NULL;
}

void	Brain::setIdea(size_t idx, const std::string& new_idea) {
	if (idx < IDEAS_MAX)
		this->ideas[idx] = new_idea;
	else
		std::cerr << "index accepts 0 to 99" << std::endl;
}
