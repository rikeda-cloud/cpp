#include "FileReplacer.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "argc != 3" << std::endl;
		return 1;
	}
	FileReplacer	replacer(argv[1], argv[2], argv[3]);
	if (replacer.Replace() == -1)
		return 1;
	return 0;
}
