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

	if (in_reader.IsFail()) {
		std::cout << "InputFile error" << std::endl;
		return 1;
	}
	OutFileReader	out_reader(argv[1] + std::string(".replace"));
	if (out_reader.IsFail()) {
		std::cout << "OutputFile error" << std::endl;
		return 1;
	}
	Replacer::Replace(&in_reader, &out_reader, std::string(argv[2]), std::string(argv[3]));
	return 0;
}
