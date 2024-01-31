#include "Zombie.hpp"

int	main(void) {
	Zombie*	zombies = zombieHorde(10, "zombie");
	delete[] zombies;
	return 0;
}

// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q MoarBrainz");
// }
