#include "ClapTrap.hpp"
#include <iostream>

void	case_die(ClapTrap player1) {
	std::cout << "--- die ---" << std::endl;
	player1.takeDamage(9);
	player1.beRepaired(9);
	player1.takeDamage(9);
	player1.takeDamage(1); // このタイミングでdie
	player1.takeDamage(1);
	player1.beRepaired(1);
}

void	case_energy_point_run_out_by_beRepaired(ClapTrap player1) {
	std::cout << "--- energy point run out by beRepaired ---" << std::endl;
	player1.beRepaired(1);
	player1.beRepaired(1);
	player1.beRepaired(1);
	player1.beRepaired(1);
	player1.beRepaired(1);
	player1.beRepaired(1);
	player1.beRepaired(1);
	player1.beRepaired(1);
	player1.beRepaired(1);
	player1.beRepaired(1); // このタイミングでenergy pointが尽きる
	player1.beRepaired(1);
}

void	case_energy_point_run_out_by_attack(ClapTrap player1) {
	std::cout << "--- energy point run out by attack ---" << std::endl;
	player1.attack("enemy");
	player1.attack("enemy");
	player1.attack("enemy");
	player1.attack("enemy");
	player1.attack("enemy");
	player1.attack("enemy");
	player1.attack("enemy");
	player1.attack("enemy");
	player1.attack("enemy");
	player1.attack("enemy"); // このタイミングでenergy pointが尽きる
	player1.attack("enemy");
}

int	main(void) {
	ClapTrap	trap("TRAP");

	case_die(trap);
	case_energy_point_run_out_by_beRepaired(trap);
	case_energy_point_run_out_by_attack(trap);

	return 0;
}
