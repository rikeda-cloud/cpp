#include "FragTrap.hpp"
#include <iostream>

void	case_equal_operator(void) {
	std::cout << "--- test operator= ---" << std::endl;
	ClapTrap*	trap = new FragTrap("EqualOperator");
	for (int i = 0; i < 99; ++i)
		trap->beRepaired(1);
	FragTrap	new_trap("TMP");
	new_trap = *dynamic_cast<FragTrap*>(trap); // ここで代入演算
	trap->beRepaired(1);
	trap->beRepaired(1); // energy pointが足りない
	new_trap.beRepaired(1);
	new_trap.beRepaired(1); // 代入が適切にできていればenergy pointが足りない
}

void	case_copy_constructor(void) {
	std::cout << "--- test copy constructor ---" << std::endl;
	ClapTrap*	trap = new FragTrap("CopyTrap");
	for (int i = 0; i < 99; ++i)
		trap->beRepaired(1);
	FragTrap	new_trap(*dynamic_cast<FragTrap*>(trap));
	trap->beRepaired(1);
	trap->beRepaired(1); // energy pointが足りない
	new_trap.beRepaired(1);
	new_trap.beRepaired(1); // コピーが適切にできていればenergy pointが足りない
}

void	case_check_hit_point(void) {
	std::cout << "--- test hit point ---" << std::endl;
	ClapTrap*	trap = new FragTrap("HitPoint");

	trap->takeDamage(20);
	trap->takeDamage(20);
	trap->takeDamage(20);
	trap->takeDamage(20);
	trap->takeDamage(20); // このタイミングでdie
	trap->takeDamage(20);
}

void	case_other(void) {
	std::cout << "--- test other ---" << std::endl;
	ClapTrap*	trap = new FragTrap("OTHER");

	trap->attack("enemy1");
	trap->attack("enemy2");
	dynamic_cast<FragTrap*>(trap)->highFivesGuys();
}

int	main(void) {
	case_equal_operator();
	case_copy_constructor();
	case_check_hit_point();
	case_other();
	return 0;
}
