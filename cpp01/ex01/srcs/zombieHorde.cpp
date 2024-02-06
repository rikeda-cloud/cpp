#include "Zombie.hpp"
#include <iostream>

Zombie*	zombieHorde(int N, std::string name) {
	Zombie*	tmp_zombies;

	if (N <= 0) {
		std::cout << "Invalid input for the argument" << std::endl;
		tmp_zombies = NULL;
	}
	else {
		tmp_zombies = new Zombie[N];
		for (int i = 0; i < N; i++)
			tmp_zombies[i].SetName(name);
	}
	return tmp_zombies;
}
