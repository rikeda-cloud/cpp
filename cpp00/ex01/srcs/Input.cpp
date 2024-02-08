#include "Input.hpp"
#include <iostream>

bool	Input::IsIntendedString(const std::string& str, int (*is_func)(int)) {
	if (str.size() == 0)
		return false;
	for (size_t i = 0; i < str.size(); i++) {
		if (is_func(str[i]) == 0)
			return false;
	}
	return true;
}

std::string	Input::InputString(const char *prompt, int (*is_func)(int)) {
	std::string	buffer;

	std::cout << prompt << std::flush;
	while (std::getline(std::cin, buffer)) {
		if (IsIntendedString(buffer, is_func))
			break ;
		std::cout << prompt << std::flush;
	}
	return buffer;
}

size_t	Input::InputIndex(const char *prompt, size_t max_idx) {
	size_t		idx;
	std::string	buffer;

	while (true) {
		buffer = InputString(prompt, std::isdigit);
		if (std::cin.eof())
			return 0;
		else if (buffer.size() == 1) {
			idx = buffer[0] - '0';
			if (1 <= idx && idx <= max_idx)
				break ;
		}
	}
	return idx;
}
