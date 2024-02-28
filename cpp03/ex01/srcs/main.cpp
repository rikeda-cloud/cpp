#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

static void	case_equal_operator(void) {
	std::cout << "--- test operator= ---" << std::endl;
	ClapTrap*	trap = new ScavTrap("EqualOperator");
	for (unsigned i = 0; i < (ScavTrap::ENERGY_POINT - 1); ++i)
		trap->beRepaired(1);
	ScavTrap	equal_operator_trap("TMP");
	equal_operator_trap = *dynamic_cast<ScavTrap*>(trap); // ここで代入演算
	trap->beRepaired(1); // ここでenergy pointが無くなる
	trap->beRepaired(1); // energy pointが足りない
	equal_operator_trap.beRepaired(1); // ここでenergy pointが無くなる
	equal_operator_trap.beRepaired(1); // energy pointが足りない
	delete trap;
}

static void	case_copy_constructor(void) {
	std::cout << "--- test copy constructor ---" << std::endl;
	ClapTrap*	trap = new ScavTrap("CopyTrap");
	for (unsigned i = 0; i < (ScavTrap::ENERGY_POINT - 1); ++i)
		trap->beRepaired(1);
	ScavTrap	copy_trap(*dynamic_cast<ScavTrap*>(trap)); // ここでコピー
	trap->beRepaired(1); // ここでenergy pointが無くなる
	trap->beRepaired(1); // energy pointが足りない
	copy_trap.beRepaired(1); // ここでenergy pointが無くなる
	copy_trap.beRepaired(1); // energy pointが足りない
	delete trap;
}

static void	case_check_hit_point(void) {
	std::cout << "--- test hit point ---" << std::endl;
	ClapTrap*	trap = new ScavTrap("HitPoint");

	const unsigned int damage = 19;
	for (unsigned i = 0; i < (ScavTrap::HIT_POINT / damage); ++i)
		trap->takeDamage(damage);
	trap->takeDamage(damage); // このタイミングでdie
	trap->takeDamage(damage);
	delete trap;
}

static void	case_other(void) {
	std::cout << "--- test other ---" << std::endl;
	ClapTrap*	trap = new ScavTrap("OTHER");

	trap->attack("enemy1");
	dynamic_cast<ScavTrap*>(trap)->guardGate();
	delete trap;
}

int	main(void) {
	case_equal_operator();
	case_copy_constructor();
	case_check_hit_point();
	case_other();

	return 0;
}

// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q scavtrap");
// }
