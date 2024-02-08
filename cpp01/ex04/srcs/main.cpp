#include "FileReplacer.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "argc != 3" << std::endl;
		return 1;
	}
	FileReplacer	replacer(argv[1]);
	if (replacer.Replace(argv[2], argv[3]) == -1)
		return 1;
	return 0;
}
