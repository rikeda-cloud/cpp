#include "Harl.hpp"

int	main(void) {
	Harl	harl;
	// harl.complain("DEBUG");
	harl.complain("WARNING");
	// harl.complain("ERROR");
	// harl.complain("INFO");
	return 0;
}
	__attribute__((destructor)) static void destructor()
{
   system("leaks -q HarlFilter");
}
