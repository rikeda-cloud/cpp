#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

void	case_equal_operator(void) {
	std::cout << "--- test operator= ---" << std::endl << std::endl;
	ClapTrap*	trap = new DiamondTrap("EqualOperator");
	for (int i = 0; i < 49; ++i)
		trap->beRepaired(1);
	DiamondTrap	new_trap("TMP");
	new_trap = *dynamic_cast<DiamondTrap*>(trap); // ここで代入演算
	trap->beRepaired(1);
	trap->beRepaired(1); // energy pointが足りない
	new_trap.beRepaired(1);
	new_trap.beRepaired(1); // 代入が適切にできていればenergy pointが足りない
}

void	case_copy_constructor(void) {
	std::cout << "--- test copy constructor ---" << std::endl << std::endl;
	ClapTrap*	trap = new DiamondTrap("CopyTrap");
	for (int i = 0; i < 49; ++i)
		trap->beRepaired(1);
	DiamondTrap	new_trap(*dynamic_cast<DiamondTrap*>(trap));
	trap->beRepaired(1);
	trap->beRepaired(1); // energy pointが足りない
	new_trap.beRepaired(1);
	new_trap.beRepaired(1); // コピーが適切にできていればenergy pointが足りない
}

void	case_check_hit_point(void) {
	std::cout << "--- test hit point ---" << std::endl << std::endl;
	ClapTrap*	trap = new DiamondTrap("HitPoint");

	trap->takeDamage(20);
	trap->takeDamage(20);
	trap->takeDamage(20);
	trap->takeDamage(20);
	trap->takeDamage(20); // このタイミングでdie
	trap->takeDamage(20);
}

void	case_other(void) {
	std::cout << "--- test other ---" << std::endl << std::endl;
	ClapTrap*	trap = new DiamondTrap("OTHER");

	trap->attack("enemy1");
	trap->ClapTrap::attack("enemy2");
	dynamic_cast<DiamondTrap*>(trap)->guardGate();
	dynamic_cast<DiamondTrap*>(trap)->highFivesGuys();
	dynamic_cast<DiamondTrap*>(trap)->whoAmI();
}

int	main(void) {
	case_equal_operator();
	case_copy_constructor();
	case_check_hit_point();
	case_other();
	return 0;
}
