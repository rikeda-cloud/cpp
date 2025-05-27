#include "InputUtils.hpp"
#include <iostream>

bool	InputUtils::IsIntendedString(const std::string& str, int (*is_func)(int)) {
	if (str.size() == 0)
		return false;
	for (size_t i = 0; i < str.size(); i++) {
		if (is_func(str[i]) == 0)
			return false;
	}
	return true;
}

std::string	InputUtils::InputString(const char *prompt, int (*is_func)(int)) {
	std::string	input_buffer;

	std::cout << prompt << std::flush;
	while (std::getline(std::cin, input_buffer)) {
		if (IsIntendedString(input_buffer, is_func))
			break ;
		std::cout << prompt << std::flush;
	}
	return input_buffer;
}

size_t	InputUtils::InputIndex(const char *prompt, size_t max_idx) {
	size_t		idx;
	std::string	input_buffer;

	while (true) {
		input_buffer = InputString(prompt, std::isdigit);
		if (std::cin.eof())
			return 0;
		else if (input_buffer.size() == 1) {
			idx = input_buffer[0] - '0';
			if (1 <= idx && idx <= max_idx)
				break ;
		}
	}
	return idx;
}
