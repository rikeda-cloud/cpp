#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) : name("NONAME-ZOMBIE") {
	std::cout << "CREATE " << name << std::endl;
}

Zombie::Zombie(std::string zombie_name) : name(zombie_name) {
	std::cout << "CREATE " << name << std::endl;
}

Zombie::Zombie(const Zombie& zombie) : name(zombie.name) {
	std::cout << "COPY " << name << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "DELETE " << name << std::endl;
}

Zombie&	Zombie::operator=(const Zombie& zombie) {
	if (this != &zombie)
		this->name = zombie.name;
	return *this;
}

void	Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::SetName(std::string zombie_name) {
	name = zombie_name;
}
