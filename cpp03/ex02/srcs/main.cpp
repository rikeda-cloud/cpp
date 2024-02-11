#include "FragTrap.hpp"

int	main(void) {
	FragTrap	my("my");
	FragTrap	enemy("enemy");

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
	return 0;
}
