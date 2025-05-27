#include "ClapTrap.hpp"
#include <iostream>
#include <limits>

static void	case_die(ClapTrap player) {
	std::cout << "--- die ---" << std::endl;
	player.takeDamage(9);
	player.beRepaired(9);
	player.takeDamage(9);
	player.takeDamage(1); // このタイミングでdie
	player.takeDamage(1);
	player.beRepaired(1);
}

static void	case_energy_point_run_out_by_beRepaired(ClapTrap player) {
	std::cout << "--- energy point run out by beRepaired ---" << std::endl;
	for (unsigned i = 0; i < (ClapTrap::ENERGY_POINT - 1); ++i)
		player.beRepaired(1);
	player.beRepaired(1); // このタイミングでenergy pointが尽きる
	player.beRepaired(1);
	player.beRepaired(1);
}

static void	case_energy_point_run_out_by_attack(ClapTrap player) {
	std::cout << "--- energy point run out by attack ---" << std::endl;
	for (unsigned i = 0; i < (ClapTrap::ENERGY_POINT - 1); ++i)
		player.attack("enemy");
	player.attack("enemy"); // このタイミングでenergy pointが尽きる
	player.attack("enemy");
	player.attack("enemy");
}

static void	case_hit_point_over_flow(ClapTrap player) {
	std::cout << "--- hit point over flow ---" << std::endl;
	player.beRepaired(std::numeric_limits<unsigned int>::max() - 8);
	player.takeDamage(1); // オーバーフローガードしないとここでdie
	player.takeDamage(1);
	player.attack("enemy");
}

int	main(void) {
	ClapTrap	trap("TRAP");

	case_die(trap);
	case_energy_point_run_out_by_beRepaired(trap);
	case_energy_point_run_out_by_attack(trap);
	case_hit_point_over_flow(trap);

	return 0;
}

// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q claptrap");
// }
