#include "Zombie.hpp"
#include <string>

void	randomChump(std::string name) {
	Zombie	tmp;
	
	tmp.setName(name);
	tmp.announce();
}
