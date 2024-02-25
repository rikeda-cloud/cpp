#include "ClapTrap.hpp"
#include <iostream>
#include <limits>

void	case_die(ClapTrap player) {
	player.takeDamage(9);
	player.beRepaired(9);
	player.takeDamage(9);
	player.takeDamage(1); // このタイミングでdie
	player.takeDamage(1);
	player.beRepaired(1);
}

void	case_energy_point_run_out_by_beRepaired(ClapTrap player) {
	player.beRepaired(1);
	player.beRepaired(1);
	player.beRepaired(1);
	player.beRepaired(1);
	player.beRepaired(1);
	player.beRepaired(1);
	player.beRepaired(1);
	player.beRepaired(1);
	player.beRepaired(1);
	player.beRepaired(1); // このタイミングでenergy pointが尽きる
	player.beRepaired(1);
}

void	case_energy_point_run_out_by_attack(ClapTrap player) {
	player.attack("enemy");
	player.attack("enemy");
	player.attack("enemy");
	player.attack("enemy");
	player.attack("enemy");
	player.attack("enemy");
	player.attack("enemy");
	player.attack("enemy");
	player.attack("enemy");
	player.attack("enemy"); // このタイミングでenergy pointが尽きる
	player.attack("enemy");
}

void	case_hit_point_over_flow(ClapTrap player) {
	player.beRepaired(std::numeric_limits<unsigned int>::max() - 8);
	player.takeDamage(1); // オーバーフローガードしないとここでdie
	player.takeDamage(1);
	player.attack("enemy");
}

int	main(void) {
	ClapTrap	trap("TRAP");

	std::cout << "--- die ---" << std::endl;
	case_die(trap);
	std::cout << "--- energy point run out by beRepaired ---" << std::endl;
	case_energy_point_run_out_by_beRepaired(trap);
	std::cout << "--- energy point run out by attack ---" << std::endl;
	case_energy_point_run_out_by_attack(trap);
	std::cout << "--- hit point over flow ---" << std::endl;
	case_hit_point_over_flow(trap);

	return 0;
}
