#include "FragTrap.hpp"
#include <iostream>

static void	case_equal_operator(void) {
	std::cout << "--- test operator= ---" << std::endl;
	ClapTrap*	trap = new FragTrap("EqualOperator");
	for (unsigned i = 0; i < (FragTrap::ENERGY_POINT - 1); ++i)
		trap->beRepaired(1);
	FragTrap	equal_operator_trap("TMP");
	equal_operator_trap = *dynamic_cast<FragTrap*>(trap); // ここで代入演算
	trap->beRepaired(1); // ここでenergy pointが無くなる
	trap->beRepaired(1); // energy pointが足りない
	equal_operator_trap.beRepaired(1); // ここでenergy pointが無くなる
	equal_operator_trap.beRepaired(1); // energy pointが足りない
	delete trap;
}

static void	case_copy_constructor(void) {
	std::cout << "--- test copy constructor ---" << std::endl;
	ClapTrap*	trap = new FragTrap("CopyTrap");
	for (unsigned i = 0; i < (FragTrap::ENERGY_POINT - 1); ++i)
		trap->beRepaired(1);
	FragTrap	copy_trap(*dynamic_cast<FragTrap*>(trap)); // ここでコピー
	trap->beRepaired(1); // ここでenergy pointが無くなる
	trap->beRepaired(1); // energy pointが足りない
	copy_trap.beRepaired(1); // ここでenergy pointが無くなる
	copy_trap.beRepaired(1); // energy pointが足りない
	delete trap;
}

static void	case_check_hit_point(void) {
	std::cout << "--- test hit point ---" << std::endl;
	ClapTrap*	trap = new FragTrap("HitPoint");

	const unsigned int damage = 19;
	for (unsigned i = 0; i < (FragTrap::HIT_POINT / damage); ++i)
		trap->takeDamage(damage);
	trap->takeDamage(damage); // このタイミングでdie
	trap->takeDamage(damage);
	delete trap;
}

static void	case_other(void) {
	std::cout << "--- test other ---" << std::endl;
	ClapTrap*	trap = new FragTrap("OTHER");

	trap->attack("enemy1");
	dynamic_cast<FragTrap*>(trap)->highFivesGuys();
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
//    system("leaks -q fragtrap");
// }
