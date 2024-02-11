#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	my("my");
	ClapTrap	enemy("enemy");

	my.attack(enemy.getName());
	my.takeDamage(1);
	my.beRepaired(1);
	my.attack(enemy.getName());
	my.takeDamage(8);
	my.beRepaired(1);
	my.takeDamage(1);
	my.takeDamage(1);
	my.beRepaired(1);
	my.beRepaired(1);
	my.beRepaired(1);
	my.beRepaired(1);
	my.attack(enemy.getName());
	my.beRepaired(1);
	my.beRepaired(1);
	my.takeDamage(100);
	my.beRepaired(1);

	return 0;
}
