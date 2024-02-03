#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	my("my");
	ClapTrap	enemy("enemy");

	my.attack(enemy.getName());
	my.takeDamege(1);
	my.beRepaired(1);
	my.takeDamege(9);
	my.takeDamege(1);
	my.beRepaired(1);
	my.beRepaired(1);
	my.beRepaired(1);
	my.attack(enemy.getName());
	my.attack(enemy.getName());
	my.attack(enemy.getName());
	my.attack(enemy.getName());
	my.attack(enemy.getName());
	my.beRepaired(1);
	my.beRepaired(1);
	my.beRepaired(1);
	return 0;
}
