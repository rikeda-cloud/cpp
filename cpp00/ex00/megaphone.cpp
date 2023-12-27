#include <iostream>

static void	_megaphone(int argc, const char **argv) {
	const static std::string default_str("* LOUD AND UNBEARABLE FEEDBACK NOISE *");

	if (argc == 1)
		std::cout << default_str;
	else {
		for (int i = 1; i < argc; i++) {
			std::string str(argv[i]);
			std::transform(str.begin(), str.end(), str.begin(), toupper);
			std::cout << str;
		}
	}
	std::cout << std::endl;
}

int	main(int argc, const char **argv) {
	_megaphone(argc, argv);
	return 0;
}
