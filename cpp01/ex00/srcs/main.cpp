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
	delete new_zombie1;
	delete new_zombie2;
	delete new_zombie3;
	std::cout << std::endl;

	std::cout << "--- randomZombie ---" << std::endl;
	randomChump("randomZombie1");
	randomChump("randomZombie2");
	randomChump("randomZombie3");
	std::cout << std::endl;

	std::cout << "--- NormalZombie ---" << std::endl;
	Zombie	normal_zombie1("normalZombie1");
	Zombie	normal_zombie2("normalZombie2");
	Zombie	normal_zombie3("normalZombie3");
	normal_zombie1.announce();
	normal_zombie2.announce();
	normal_zombie3.announce();
	std::cout << std::endl;

	std::cout << "--- destructor of a local variable created inside the main function is called ---" << std::endl;
	return 0;
}

// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q Brainz");
// }
