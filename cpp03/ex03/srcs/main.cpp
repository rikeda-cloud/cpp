#include "DiamondTrap.hpp"

int	main(void) {
	DiamondTrap	my("my");
	DiamondTrap	enemy("enemy");

	my.attack(enemy.getName());
	my.takeDamage(1);
	my.beRepaired(1);
	my.takeDamage(9);
	my.takeDamage(1);
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
	my.whoAmI();
	return 0;
}
