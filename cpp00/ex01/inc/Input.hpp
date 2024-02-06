#ifndef CPP00_EX01_Input_H_
# define CPP00_EX01_Input_H_

#include <string>

class Input {
private:
	static bool	IsIntendedString(const std::string&, int (*f)(int));

public:
	enum e_continue {INPUT_CONTINUE = 0, INPUT_END = 1};

	static std::string	InputString(const char *prompt, int (*f)(int));
	static size_t		InputIndex(const char *prompt, size_t max_idx);
};

#endif
