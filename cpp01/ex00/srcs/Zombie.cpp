#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {}

Zombie::Zombie(const Zombie& zombie) : name(zombie.name){}

Zombie&	Zombie::operator=(const Zombie& zombie) {
	if (this != &zombie)
		this->name = zombie.name;
	return *this;
}

Zombie::~Zombie(void) {
	std::cout << "DELETE " << name << std::endl;
}

void	Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::SetName(std::string name) {
	this->name = name;
}
