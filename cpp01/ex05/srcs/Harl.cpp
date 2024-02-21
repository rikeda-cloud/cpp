#include "Harl.hpp"
#include "Colors.hpp"
#include <iostream>

Harl::Harl(void) {
	method_array_[0] = &Harl::debug;
	method_array_[1] = &Harl::info;
	method_array_[2] = &Harl::warning;
	method_array_[3] = &Harl::error;
	level_string_array_[0] = "DEBUG";
	level_string_array_[1] = "INFO";
	level_string_array_[2] = "WARNING";
	level_string_array_[3] = "ERROR";
}

Harl::Harl(const Harl& harl) {
	for (int i = 0; i < LEVEL_SIZE; ++i)
		this->method_array_[i] = harl.method_array_[i];
	for (int i = 0; i < LEVEL_SIZE; ++i)
		this->level_string_array_[i] = harl.level_string_array_[i];
}

Harl::~Harl(void) {}

Harl&	Harl::operator=(const Harl& harl) {
	if (this != &harl) {
		for (int i = 0; i < LEVEL_SIZE; ++i)
			this->method_array_[i] = harl.method_array_[i];
		for (int i = 0; i < LEVEL_SIZE; ++i)
			this->level_string_array_[i] = harl.level_string_array_[i];
	}
	return *this;
}

void	Harl::debug(void) {
	std::cout << Colors::BLUE << "[ DEBUG ]" << Colors::RESET << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void	Harl::info(void) {
	std::cout << Colors::WHITE << "[ INFO ]" << Colors::RESET << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void	Harl::warning(void) {
	std::cout << Colors::YELLOW << "[ WARNING ]" << Colors::RESET << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::error(void) {
	std::cout << Colors::RED << "[ ERROR ]" << Colors::RESET << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

int	Harl::LevelToIndex(std::string& level) {
	for (int i = 0; i < 4; i++) {
		if ((this->level_string_array_[i]) == level)
			return i;
	}
	return -1;
}

void	Harl::complain(std::string level) {
	const int	index = LevelToIndex(level);

	if (index != -1)
		(this->*(method_array_[index]))();
	else
		std::cerr
			<< Colors::MAGENTA
			<< "\""
			<< level
			<< "\""
			<< " is not in harl levels"
			<< Colors::RESET
			<< std::endl
			<< std::endl;
}
