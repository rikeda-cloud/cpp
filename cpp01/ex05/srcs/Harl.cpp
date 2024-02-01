#include "Harl.hpp"
#include <iostream>

Harl::Harl(void) {
}

void	Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::harl_func_ptr	Harl::_select_level(std::string level) {
	HarlDict	dict;

	dict.append("DEBUG", Harl::debug);
	dict.append("INFO", Harl::info);
	dict.append("WARNING", Harl::warning);
	dict.append("ERROR", Harl::error);

	for (int i = 0; i < dict.size(); i++) {
		if (dict.getHarlPair(i)->getKey() == level)
			return dict.getHarlPair(i)->getValue();
	}
	return NULL;
}

void	Harl::complain(std::string level) {
	Harl::harl_func_ptr func_ptr = _select_level(level);

	if (func_ptr)
		func_ptr();
}
