#include <iostream>

static std::string	_toupper_string(std::string str) {
	for (int i = 0; i < str.size(); i++)
		str[i] = std::toupper(str[i]);
	return str;
}

static void	_megaphone(int argc, const char **argv) {
	const char	default_str[] = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (argc == 1)
		std::cout << default_str;
	else {
		for (int i = 1; i < argc; i++)
			std::cout << _toupper_string(argv[i]);
	}
	std::cout << std::endl;
}

int	main(int argc, const char **argv) {
	_megaphone(argc, argv);
	return 0;
}
