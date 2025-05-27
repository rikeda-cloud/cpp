#ifndef CPP00_EX01_InputUtils_H_
# define CPP00_EX01_InputUtils_H_

#include <string>

class InputUtils {
public:
	static std::string	InputString(const char *prompt, int (*is_func)(int));
	static size_t		InputIndex(const char *prompt, size_t max_idx);

private:
	InputUtils(void);
	InputUtils(const InputUtils&);
	~InputUtils(void);
	void	operator=(const InputUtils&);

	static bool	IsIntendedString(const std::string&, int (*is_func)(int));
};

#endif
