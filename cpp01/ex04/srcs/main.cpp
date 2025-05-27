#include "Replacer.hpp"
#include "OutFileReader.hpp"
#include "InFileReader.hpp"
#include <iostream>

int	main(int argc, const char **argv) {
	if (argc != 4) {
		std::cout << "argc != 4" << std::endl;
		return 1;
	}

	InFileReader	in_reader(argv[1]);
	if (in_reader.isFail()) {
		std::cerr << "InputFile error" << std::endl;
		return 1;
	}

	OutFileReader	out_reader(argv[1] + std::string(".replace"));
	if (out_reader.isFail()) {
		std::cerr << "OutputFile error" << std::endl;
		return 1;
	}

	if (Replacer::replace(&in_reader, &out_reader, argv[2], argv[3])) {
		std::cerr << "Replace error" << std::endl;
		return 1;
	}
	return 0;
}
