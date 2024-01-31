#include <iostream>
#include "FileReplacer.hpp"

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "argc != 3" << std::endl;
		return 1;
	}
	FileReplacer	replacer(argv[1], argv[2], argv[3]);
	replacer.replace();
	return 0;
}
