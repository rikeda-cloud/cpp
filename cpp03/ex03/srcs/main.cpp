#include "DiamondTrap.hpp"

int	main(void) {
	DiamondTrap	my("my");
	DiamondTrap	enemy("enemy");

	my.attack(enemy.getName());
	my.takeDamege(1);
	my.beRepaired(1);
	my.takeDamege(9);
	my.takeDamege(1);
	my.beRepaired(1);
	my.beRepaired(1);
	my.beRepaired(1);
	my.highFivesGuys();
	my.attack(enemy.getName());
	my.attack(enemy.getName());
	my.attack(enemy.getName());
	my.attack(enemy.getName());
	my.attack(enemy.getName());
	my.highFivesGuys();
	my.beRepaired(1);
	my.beRepaired(1);
	my.beRepaired(1);
	return 0;
}
