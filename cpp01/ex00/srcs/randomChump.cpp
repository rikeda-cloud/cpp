#include "Zombie.hpp"
#include <string>

void	randomChump(std::string name) {
	Zombie	tmp_zombie(name);
	
	tmp_zombie.announce();
}
