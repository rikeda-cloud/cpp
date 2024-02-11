#include "FragTrap.hpp"
#include "Colors.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	hit_point_ = FragTrap::HIT_POINT;
	energy_point_ = FragTrap::ENERGY_POINT;
	attack_damage_ = FragTrap::ATTACK_DAMAGE;
	std::cout << Colors::CYAN << "FragTrap constructor called" << Colors::RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragtrap) : ClapTrap(fragtrap) {
	std::cout << Colors::CYAN << "FragTrap copy constructor called" << Colors::RESET << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << Colors::WHITE << "FragTrap destructor called" << Colors::RESET << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& fragtrap) {
	if (this != &fragtrap)
		ClapTrap::operator=(fragtrap);
	return *this;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << Colors::YELLOW << "high fives request ???" << Colors::RESET << std::endl;
}
