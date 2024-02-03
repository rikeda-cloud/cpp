#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "Colors.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	hit_point_ = 100;
	energy_point_ = 50;
	attack_damage_ = 20;
	std::cout << Colors::CYAN << "The ScavTrap constructor will be called" << Colors::RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap) : ClapTrap(scavtrap) {
	std::cout << Colors::CYAN << "The ScavTrap copy constructor will be called" << Colors::RESET << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << Colors::WHITE << "The ScavTrap destructor will be called" << Colors::RESET << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& scavtrap) {
	ClapTrap::operator=(scavtrap);
	return *this;
}

void	ScavTrap::guardGate(void) {
	std::cout << Colors::YELLOW <<  getName() << " is now in Gate keeper mode" << Colors::RESET << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (hit_point_ == 0)
		std::cout << Colors::MAGENTA << getName() << " is already dead" << Colors::RESET << std::endl;
	else if (energy_point_ == 0)
		std::cout << Colors::MAGENTA << "No energy point" << Colors::RESET << std::endl;
	else {
		energy_point_--;
		std::cout << Colors::BLUE << "ScavTrap " << getName() << " attacks " << target << ", causing " << attack_damage_ << " points of damage!" << Colors::RESET << std::endl;
	}
}
