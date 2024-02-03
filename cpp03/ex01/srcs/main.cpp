#include "ScavTrap.hpp"

int	main(void) {
	ScavTrap	my("my");
	ScavTrap	enemy("enemy");

	my.attack(enemy.getName());
	my.takeDamege(1);
	my.beRepaired(1);
	my.takeDamege(9);
	my.takeDamege(1);
	my.beRepaired(1);
	my.beRepaired(1);
	my.beRepaired(1);
	my.guardGate();
	my.attack(enemy.getName());
	my.attack(enemy.getName());
	my.attack(enemy.getName());
	my.attack(enemy.getName());
	my.attack(enemy.getName());
	my.guardGate();
	my.beRepaired(1);
	my.beRepaired(1);
	my.beRepaired(1);
	return 0;
}
