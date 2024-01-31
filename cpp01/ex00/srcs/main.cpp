#include "Zombie.hpp"

int	main(void) {
	Zombie*	zombie1 = newZombie("Zombie1");
	Zombie*	zombie2 = newZombie("Zombie2");
	Zombie*	zombie3 = newZombie("Zombie3");
	Zombie*	zombie4 = newZombie("Zombie4");
	Zombie*	zombie5 = newZombie("Zombie5");

	randomChump("Zombie6");
	randomChump("Zombie7");
	randomChump("Zombie9");
	randomChump("Zombie9");
	randomChump("Zombie10");
	delete zombie1;
	delete zombie2;
	delete zombie3;
	delete zombie4;
	delete zombie5;
	return 0;
}

// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q Brainz");
// }
