#include "Zombie.hpp"
#include <iostream>

Zombie*	zombieHorde(int N, std::string name) {
	Zombie*	zombies;

	if (N <= 0) {
		std::cerr << "Invalid input for the argument" << std::endl;
		zombies = NULL;
	}
	else {
		zombies = new Zombie[N];
		for (int i = 0; i < N; ++i)
			zombies[i].SetName(name);
	}
	return zombies;
}
