#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

void	case_equal_operator(void) {
	std::cout << "--- test operator= ---" << std::endl;
	ClapTrap*	trap = new ScavTrap("EqualOperator");
	for (int i = 0; i < 49; ++i)
		trap->beRepaired(1);
	ScavTrap	new_trap("TMP");
	new_trap = *dynamic_cast<ScavTrap*>(trap); // ここで代入演算
	trap->beRepaired(1);
	trap->beRepaired(1); // energy pointが足りない
	new_trap.beRepaired(1);
	new_trap.beRepaired(1); // 代入が適切にできていればenergy pointが足りない
}

void	case_copy_constructor(void) {
	std::cout << "--- test copy constructor ---" << std::endl;
	ClapTrap*	trap = new ScavTrap("CopyTrap");
	for (int i = 0; i < 49; ++i)
		trap->beRepaired(1);
	ScavTrap new_trap(*dynamic_cast<ScavTrap*>(trap));
	trap->beRepaired(1);
	trap->beRepaired(1); // energy pointが足りない
	new_trap.beRepaired(1);
	new_trap.beRepaired(1); // コピーが適切にできていればenergy pointが足りない
}

void	case_check_hit_point(void) {
	std::cout << "--- test hit point ---" << std::endl;
	ClapTrap*	trap = new ScavTrap("HitPoint");

	trap->takeDamage(20);
	trap->takeDamage(20);
	trap->takeDamage(20);
	trap->takeDamage(20);
	trap->takeDamage(20); // このタイミングでdie
	trap->takeDamage(20);
}

void	case_other(void) {
	std::cout << "--- test other ---" << std::endl;
	ClapTrap*	trap = new ScavTrap("OTHER");

	trap->attack("enemy1");
	trap->attack("enemy2");
	dynamic_cast<ScavTrap*>(trap)->guardGate();
}

int	main(void) {
	case_equal_operator();
	case_copy_constructor();
	case_check_hit_point();
	case_other();
	return 0;
}
