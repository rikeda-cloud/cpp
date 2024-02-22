#include "Zombie.hpp"
#include <string>

Zombie*	newZombie(std::string name) {
	Zombie*	tmp = new Zombie;
	tmp->SetName(name);
	return tmp;
}
