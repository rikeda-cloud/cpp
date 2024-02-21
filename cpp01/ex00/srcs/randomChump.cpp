#include "Zombie.hpp"
#include <string>

void	randomChump(std::string name) {
	Zombie	tmp(name);
	
	tmp.announce();
}
