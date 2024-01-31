#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string zombie_name) : name(zombie_name) {
	std::cout << "create " << name << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "delete " << name << std::endl;
}

void	Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
