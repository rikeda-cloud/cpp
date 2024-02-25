#include "ClapTrap.hpp"
#include "Colors.hpp"
#include <iostream>
#include <limits>

ClapTrap::ClapTrap(std::string name)
	:	name_(name),
		hit_point_(ClapTrap::HIT_POINT),
		energy_point_(ClapTrap::ENERGY_POINT),
		attack_damage_(ClapTrap::ATTACK_DAMAGE) {
	std::cout << Colors::CYAN << "ClapTrap constructor called" << Colors::RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap)
	:	name_(claptrap.name_),
		hit_point_(claptrap.hit_point_),
		energy_point_(claptrap.energy_point_),
		attack_damage_(claptrap.attack_damage_) {
	std::cout << Colors::CYAN << "ClapTrap copy constructor called" << Colors::RESET << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << Colors::WHITE << "ClapTrap destructor called" << Colors::RESET << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& claptrap) {
	if (this != &claptrap) {
		this->name_ = claptrap.name_;
		this->hit_point_ = claptrap.hit_point_;
		this->energy_point_ = claptrap.energy_point_;
		this->attack_damage_ = claptrap.attack_damage_;
	}
	return *this;
}

void	ClapTrap::attack(const std::string& target) {
	if (hit_point_ == 0)
		std::cout << Colors::MAGENTA << name_ << " is already dead" << Colors::RESET << std::endl;
	else if (energy_point_ == 0)
		std::cout << Colors::MAGENTA << "No energy point" << Colors::RESET << std::endl;
	else {
		--energy_point_;
		std::cout << Colors::BLUE << "ClapTrap " << name_ << " attacks " << target << ", causing " << attack_damage_ << " points of damage!" << Colors::RESET << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (hit_point_ == 0)
		std::cout << Colors::MAGENTA << name_ << " is already dead" << Colors::RESET << std::endl;
	else {
		std::cout << Colors::RED << name_ << " has taken " << amount << " points of damage!" << Colors::RESET << std::endl;
		hit_point_ = (hit_point_ < amount) ? 0 : hit_point_ - amount;
		if (hit_point_ == 0)
			std::cout << Colors::MAGENTA << name_ << " is dead" << Colors::RESET << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (hit_point_ == 0)
		std::cout << Colors::MAGENTA << name_ << " is already dead" << Colors::RESET << std::endl;
	else if (energy_point_ == 0)
		std::cout << Colors::MAGENTA << "No energy point" << Colors::RESET << std::endl;
	else {
		--energy_point_;
		std::cout << Colors::GREEN << name_ << " repaired " << amount << " points" << Colors::RESET << std::endl;
		if ((std::numeric_limits<unsigned int>::max() - amount) < hit_point_) {
			hit_point_ = std::numeric_limits<unsigned int>::max();
			std::cout << Colors::GREEN << "The hit points have been restored to their maximum value" << Colors::RESET << std::endl;
		}
		else
			hit_point_ += amount;
	}
}
