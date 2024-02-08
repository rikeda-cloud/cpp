#ifndef CPP00_EX01_Input_H_
# define CPP00_EX01_Input_H_

#include <string>

class Input {
private:
	Input(void);
	Input(const Input&);
	~Input(void);
	void	operator=(const Input& input);

	static bool	IsIntendedString(const std::string&, int (*)(int));

public:
	static std::string	InputString(const char *prompt, int (*)(int));
	static size_t		InputIndex(const char *prompt, size_t max_idx);
};

#endif
