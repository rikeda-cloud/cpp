#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "Colors.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	hit_point_ = 100;
	energy_point_ = 100;
	attack_damage_ = 30;
	std::cout << Colors::CYAN << "The FragTrap constructor will be called" << Colors::RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragtrap) : ClapTrap(fragtrap) {
	std::cout << Colors::CYAN << "The FragTrap copy constructor will be called" << Colors::RESET << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << Colors::WHITE << "The FragTrap destructor will be called" << Colors::RESET << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& fragtrap) {
	ClapTrap::operator=(fragtrap);
	return *this;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << Colors::YELLOW << "high fives request ???" << Colors::RESET << std::endl;
}
