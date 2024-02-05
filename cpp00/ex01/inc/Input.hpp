#ifndef CPP00_EX01_Input_H_
# define CPP00_EX01_Input_H_

#include <string>

class Input {
public:
	static bool			IsSpaceString(std::string&);
	static std::string	InputString(const std::string& prompt);
	static size_t		InputIndex(const std::string& prompt, size_t max_idx);
};

#endif
