#include "Zombie.hpp"
#include <string>

Zombie*	newZombie(std::string name) {
	Zombie*	tmp = new Zombie;
	tmp->setName(name);
	return tmp;
}
