#include "Zombie.hpp"
#include <iostream>

int	main(void) {
	std::cout << "--- newZombie ---" << std::endl;
	Zombie*	new_zombie1 = newZombie("newZombie1");
	Zombie*	new_zombie2 = newZombie("newZombie2");
	Zombie*	new_zombie3 = newZombie("newZombie3");
	new_zombie1->announce();
	new_zombie2->announce();
	new_zombie3->announce();
	std::cout << std::endl;

	std::cout << "--- randomZombie ---" << std::endl;
	randomChump("randomZombie1");
	randomChump("randomZombie2");
	randomChump("randomZombie3");
	std::cout << std::endl;

	std::cout << "--- delete newZombie ---" << std::endl;
	delete new_zombie1;
	delete new_zombie2;
	delete new_zombie3;

	return 0;
}

// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q Brainz");
// }
