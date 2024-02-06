#include "Zombie.hpp"
#include <iostream>

int	main(void) {
	Zombie*	zombies;

	std::cout << "--- CREATE 0 Zombies ---" << std::endl;
	zombies = zombieHorde(0, "Zero-Zombie");
	std::cout << std::endl;

	std::cout << "--- CREATE -10 Zombies ---" << std::endl;
	zombies = zombieHorde(-10, "Minus-Ten-Zombie");
	std::cout << std::endl;

	std::cout << "--- CREATE 10 Zombies ---" << std::endl;
	zombies = zombieHorde(10, "Ten-Zombie");
	std::cout << std::endl;

	std::cout << "--- announce 10 Zombies ---" << std::endl;
	for (int i = 0; i < 10; i++)
		zombies[i].announce();
	std::cout << std::endl;

	std::cout << "--- rename 10 Zombies ---" << std::endl;
	for (int i = 0; i < 10; i++)
		zombies[i].SetName(std::string("Rename-Zombies"));
	std::cout << std::endl;

	std::cout << "--- announce rename 10 Zombies ---" << std::endl;
	for (int i = 0; i < 10; i++)
		zombies[i].announce();
	std::cout << std::endl;

	std::cout << "--- delete rename 10 Zombies ---" << std::endl;
	delete[] zombies;

	return 0;
}

// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q MoarBrainz");
// }
