#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "Colors.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	hit_point_ = ScavTrap::HIT_POINT;
	energy_point_ = ScavTrap::ENERGY_POINT;
	attack_damage_ = ScavTrap::ATTACK_DAMAGE;
	std::cout << Colors::CYAN << "ScavTrap constructor called" << Colors::RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap) : ClapTrap(scavtrap) {
	std::cout << Colors::CYAN << "ScavTrap copy constructor called" << Colors::RESET << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << Colors::WHITE << "ScavTrap destructor called" << Colors::RESET << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& scavtrap) {
	if (this != &scavtrap)
		ClapTrap::operator=(scavtrap);
	return *this;
}

void	ScavTrap::guardGate(void) {
	std::cout << Colors::YELLOW <<  name_ << " is now in Gate keeper mode" << Colors::RESET << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (hit_point_ == 0)
		std::cout << Colors::MAGENTA << name_ << " is already dead" << Colors::RESET << std::endl;
	else if (energy_point_ == 0)
		std::cout << Colors::MAGENTA << "No energy point" << Colors::RESET << std::endl;
	else {
		energy_point_--;
		std::cout << Colors::BLUE << "ScavTrap " << name_ << " attacks " << target << ", causing " << attack_damage_ << " points of damage!" << Colors::RESET << std::endl;
	}
}
