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
	std::string all_chars = in_reader.GetAllChars();
	Replacer::Replace(all_chars, argv[2], argv[3]);
	out_reader.Save(all_chars);
	return 0;
}
