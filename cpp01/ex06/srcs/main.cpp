#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	Harl	harl;

	if (argc == 2)
		harl.complain(argv[1]);
	else
		harl.complain("ERROR");
	return 0;
}

	__attribute__((destructor)) static void destructor()
{
   system("leaks -q HarlFilter");
}
